#include <stdio.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x > y) return -1;
    if (x < y) return 1;
    return 0;
}

int main(void) {
    int N, K;
    long long X;
    scanf("%d %d %lld", &N, &K, &X);
    long long A[N];
    for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

    qsort(A, N, sizeof(long long), cmp_desc);

    int range = N - K;
    long long sake_sum = 0;
    int ans = -1;
    for (int M = range + 1; M <= N; M++) {
        sake_sum += A[M - 1];
        if (sake_sum >= X) {
            ans = M;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
