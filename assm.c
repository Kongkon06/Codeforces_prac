
#include <windows.h>

#define EDIT_ID 101

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc = {0};
    MSG msg;
    HWND hwndMain, hwndEdit;
    
    // Define window class
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "MyWindowClass";
    
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONERROR);
        return 0;
    }
    
    // Create main window
    hwndMain = CreateWindowEx(
        0, "MyWindowClass", "Electra", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 600, 400,
        NULL, NULL, hInstance, NULL
    );
    
    if (!hwndMain) {
        MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONERROR);
        return 0;
    }
    
    // Create edit control
    hwndEdit = CreateWindowEx(
        WS_EX_CLIENTEDGE, "EDIT", NULL,
        WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL,
        10, 10, 560, 340,
        hwndMain, (HMENU)EDIT_ID, hInstance, NULL
    );
    
    SendMessage(hwndEdit, EM_SETLIMITTEXT, 0, 0); // No text limit
    SetWindowPos(hwndMain, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    
    ShowWindow(hwndMain, nCmdShow);
    UpdateWindow(hwndMain);
    
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hwndEdit;
    RECT rect;
    
    switch (uMsg) {
        case WM_CREATE:
            hwndEdit = GetDlgItem(hwnd, EDIT_ID);
            break;
        
        case WM_SIZE:
            GetClientRect(hwnd, &rect);
            MoveWindow(hwndEdit, 10, 10, rect.right - 20, rect.bottom - 20, TRUE);
            SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
            break;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
