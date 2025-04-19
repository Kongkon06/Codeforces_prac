#include <stdio.h>
#include <stdlib.h>

void ConsumeToEOL(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    int rows, cols;
    fputs("Enter the size\n", stdout);
    
    if (scanf("%d%d", &rows, &cols) != 2) {
        fputs("Bad number Input\n", stdout);
        exit(1);
    }
    ConsumeToEOL();

    char matrix[rows][cols];
    int starCols[3] = {0}; 
    int starRows[3] = {0};    
    int starCount = 0;

    fputs("Enter the matrix\n", stdout);
    
    for (int i = 0; i < rows; i++) {
        int j = 0;
        while (j < cols) {
            int ch = getchar();
            if (ch == '\n' || ch == EOF) break;

            matrix[i][j] = (char)ch;
            if (matrix[i][j] == '*') {
                starRows[starCount] = i;
                starCols[starCount] = j;
                starCount++;
            }
            j++;
        }
        for (; j < cols; j++) {
            matrix[i][j] = 0;
        }
        if (j == cols) ConsumeToEOL();
    }

    int finalRow = starRows[0] == starRows[1] ? starRows[2] :
                   starRows[0] == starRows[2] ? starRows[1] : starRows[0];

    int finalCol = starCols[0] == starCols[1] ? starCols[2] :
                   starCols[0] == starCols[2] ? starCols[1] : starCols[0];

    printf("The crime will happen in %d %d\n", finalRow + 1, finalCol + 1);
    return 0;
}

