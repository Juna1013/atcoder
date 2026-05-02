#include <stdio.h>

int main(void) {
    int A[4][7];
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 6; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    double count = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                int a = A[1][i];
                int b = A[2][j];
                int c = A[3][k];
                if (a != b && b != c && c != a
                    && a + b + c == 15) {
                        count++;
                    }
            }
        }
    }

    double ans = count / 216;
    printf("%f\n", ans);

    return 0;
}
