#include <windows.h>
#include <dwmapi.h>
#include <uxtheme.h>

#pragma comment(lib, "dwmapi.lib")
#pragma comment(lib, "uxtheme.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "comctl32.lib")

// Global variables
const wchar_t CLASS_NAME[] = L"EnhancedWindowClass";
HBRUSH hBrushBackground = NULL;
HFONT hFont = NULL;

// Function prototypes
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void EnableDarkMode(HWND hwnd);
void CreateCustomControls(HWND hwnd);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow) {
    // Initialize common controls
    INITCOMMONCONTROLSEX icc;
    icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icc.dwICC = ICC_STANDARD_CLASSES | ICC_WIN95_CLASSES;
    InitCommonControlsEx(&icc);

    // Create a custom background brush (light blue color)
    hBrushBackground = CreateSolidBrush(RGB(240, 248, 255));

    // Create a custom font
    hFont = CreateFontW(
        -16,                    // Height
        0,                      // Width
        0,                      // Escapement
        0,                      // Orientation
        FW_NORMAL,              // Weight
        FALSE,                  // Italic
        FALSE,                  // Underline
        FALSE,                  // StrikeOut
        DEFAULT_CHARSET,        // CharSet
        OUT_OUTLINE_PRECIS,     // OutPrecision
        CLIP_DEFAULT_PRECIS,    // ClipPrecision
        CLEARTYPE_QUALITY,      // Quality
        DEFAULT_PITCH | FF_DONTCARE, // PitchAndFamily
        L"Segoe UI"             // Font Name
    );

    // Register the window class
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = hBrushBackground;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);

    RegisterClassW(&wc);

    // Calculate window position
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int windowWidth = 800;
    int windowHeight = 600;
    int x = (screenWidth - windowWidth) / 2;
    int y = (screenHeight - windowHeight) / 2;

    // Create the main window
    HWND hwnd = CreateWindowExW(
        WS_EX_OVERLAPPEDWINDOW | WS_EX_COMPOSITED,
        CLASS_NAME,
        L"Enhanced Styled Window",
        WS_OVERLAPPEDWINDOW,
        x, y, windowWidth, windowHeight,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        MessageBoxW(NULL, L"Window Creation Failed!", L"Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    EnableDarkMode(hwnd);
    CreateCustomControls(hwnd);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {0};
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    DeleteObject(hBrushBackground);
    DeleteObject(hFont);

    return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hButton, hEdit, hLabel;

    switch (uMsg) {
        case WM_CTLCOLORBTN:
            SetBkMode((HDC)wParam, TRANSPARENT);
            SetTextColor((HDC)wParam, RGB(0, 0, 120));
            return (LRESULT)hBrushBackground;

        case WM_CTLCOLORSTATIC:
            SetBkMode((HDC)wParam, TRANSPARENT);
            SetTextColor((HDC)wParam, RGB(0, 70, 140));
            return (LRESULT)hBrushBackground;

        case WM_CTLCOLOREDIT:
            SetBkColor((HDC)wParam, RGB(255, 255, 255));
            SetTextColor((HDC)wParam, RGB(30, 30, 30));
            return (LRESULT)GetStockObject(WHITE_BRUSH);

        case WM_COMMAND:
            if (LOWORD(wParam) == 100 && HIWORD(wParam) == BN_CLICKED) {
                wchar_t buffer[256];
                GetWindowTextW(hEdit, buffer, 256);
                if (wcslen(buffer) > 0) {
                    MessageBoxW(hwnd, buffer, L"You entered:", MB_OK | MB_ICONINFORMATION);
                } else {
                    MessageBoxW(hwnd, L"Please enter some text first.", L"Empty input", MB_OK | MB_ICONWARNING);
                }
            }
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
}

void EnableDarkMode(HWND hwnd) {
    BOOL value = TRUE;
    DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &value, sizeof(value));

    DWM_WINDOW_CORNER_PREFERENCE corner = DWMWCP_ROUND;
    DwmSetWindowAttribute(hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, &corner, sizeof(corner));
}

void CreateCustomControls(HWND hwnd) {
    RECT rect;
    GetClientRect(hwnd, &rect);

    // Label
    hLabel = CreateWindowW(
        L"STATIC", L"Enter your text:",
        WS_CHILD | WS_VISIBLE | SS_LEFT,
        20, 30, rect.right - 40, 25,
        hwnd, (HMENU)101, NULL, NULL
    );

    // Edit control
    hEdit = CreateWindowExW(
        WS_EX_CLIENTEDGE, L"EDIT", L"",
        WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
        20, 60, rect.right - 40, 30,
        hwnd, (HMENU)102, NULL, NULL
    );

    // Button
    hButton = CreateWindowW(
        L"BUTTON", L"Submit",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        rect.right - 120, rect.bottom - 50, 100, 30,
        hwnd, (HMENU)100, NULL, NULL
    );

    SendMessageW(hLabel, WM_SETFONT, (WPARAM)hFont, TRUE);
    SendMessageW(hEdit, WM_SETFONT, (WPARAM)hFont, TRUE);
    SendMessageW(hButton, WM_SETFONT, (WPARAM)hFont, TRUE);
}
