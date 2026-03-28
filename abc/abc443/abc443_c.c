#include <stdio.h>

int main(void) {
    int N, T;
    scanf("%d %d", &N, &T);
    int A[N];
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    int t = 0;
    int total = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] >= t) {
            total += A[i] - t;
            t = A[i] + 100;
        }
    }

    if (t < T) total += T - t;
    printf("%d\n", total);

    return 0;
}
