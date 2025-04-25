
#include <stdio.h>

int isBalanced(int num, int n) {
    int firstHalf = 0, secondHalf = 0;

    for (int i = 0; i < n; i++) {
        int digit = num % 10;
        num /= 10;
        if (i < n / 2)
            secondHalf += digit;
        else
            firstHalf += digit;
    }

    return firstHalf == secondHalf;
}

int main() {
    int n, num;
    scanf("%d", &n);
    scanf("%d", &num);

    if (isBalanced(num, n))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

