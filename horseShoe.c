
#include <stdio.h>
#include <stdbool.h>

int main() {
    int a[4], b[4], output = 0;
    int bIndex = 0;

    printf("Enter the colors:\n");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 4; i++) {
        bool repeat = false;

        // Check if a[i] is already in b[]
        for (int j = 0; j < bIndex; j++) {
            if (b[j] == a[i]) {
                repeat = true;
                break;
            }
        }

        if (!repeat) {
            b[bIndex] = a[i];
            bIndex++;
        } else {
            output++; // Count duplicate
        }
    }

    printf("The total number of extra horseshoes is %d\n", output);
    return 0;
}

