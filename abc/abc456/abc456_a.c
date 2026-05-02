#include <stdio.h>

int main(void) {
    int X; scanf("%d", &X);

    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            int k = X - i - j;
            if (k >= 1 && k <= 6) {
                printf("Yes\n");
                return 0;
            }
        }
    }

    printf("No\n");
    return 0;
}
