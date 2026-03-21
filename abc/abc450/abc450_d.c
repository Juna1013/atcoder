#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long va = *(long long *)a;
    long long vb = *(long long *)b;
    
    if (va == vb) return 0;
    else if (va < vb) return -1;
    else return 1;
}

int main(void) {
    int N;  long long K;
    scanf("%d %lld", &N, &K);
    long long A[N]; for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

    qsort(A, N, sizeof(long long), cmp);

    long long ans = A[N-1] - A[0];
    for (int i = 1; i < N; i++) {
        long long mx = (A[i-1] > A[N-1]+K) ? A[i-1] : A[N-1]+K;
        long long mn = (A[0] < A[i]+K) ? A[0] : A[i]+K;
        long long diff = mx - mn;
        if (diff < ans) ans = diff;
    }

    printf("%lld\n", ans);

    return 0;
}
