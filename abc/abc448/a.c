#include <stdio.h>

int main(void) {
    int N, X, A; 
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A);
        if (A < X) {
            X = A;
            printf("%d\n", 1);
        } else printf("%d\n", 0);
    }
    return 0;
}
