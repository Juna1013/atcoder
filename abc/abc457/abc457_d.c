#include <stdio.h>

#define MAXN 200001

int N;
long long K;
long long A[MAXN];

int check(long long m) {
    long long total = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] < m) total += (m - A[i] + i - 1) / i;
        if (total > K) return 0;
    }
    return 1;
}

int main(void) {
    scanf("%d %lld", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }

    long long lo = 1;
    long long hi = 2e18;
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }

    printf("%lld\n", lo);
    return 0;
}
