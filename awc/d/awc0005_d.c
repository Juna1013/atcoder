#include <stdio.h>

long long A[100000];

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);
    long long total = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        total += A[i];
    }

    long long lo = 0, hi = total;
    while (lo < hi) {
        long long mid = (lo + hi + 1) / 2;

        int groups = 0;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i];
            if (sum >= mid) {
                groups++;
                sum = 0;
            }
        }

        if (groups >= K) lo = mid;
        else hi = mid - 1;
    }

    printf("%lld\n", lo);
    return 0;
}
