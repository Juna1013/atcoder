#include <stdio.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}

int main(void) {
    int N, K;
    long long X;
    if (scanf("%d %d %lld", &N, &K, &X) != 3) return 0;

    long long *A = (long long *)malloc(sizeof(long long) * N);
    if (!A) return 0;

    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    qsort(A, N, sizeof(long long), cmp_desc);

    long long *pref = (long long *)malloc(sizeof(long long) * (N + 1));
    if (!pref) return 0;
    pref[0] = 0;
    for (int i = 0; i < N; i++) {
        pref[i + 1] = pref[i] + A[i];
    }

    int ans = -1;
    for (int i = K; i <= N; i++) {
        long long sum_k = pref[i] - pref[i - K];
        if (sum_k >= X) {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);

    free(A);
    free(pref);

    return 0;
}
