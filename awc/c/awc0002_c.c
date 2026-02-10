#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);
    int A[N], B[N];
    for (int i = 0; i < N; i++) scanf("%d %d", &A[i], &B[i]);

    int max_d = 0;
    for (int i = 0; i < N; i++) {
        int d_needed;
        if (A[i] >= M) d_needed = 0;
        else d_needed = (M - A[i] + B[i] -1) / B[i];
        if (d_needed > max_d) max_d = d_needed;
    }

    printf("%d\n", max_d);
    return 0;
}
