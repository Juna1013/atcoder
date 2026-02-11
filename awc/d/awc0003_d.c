#include <stdio.h>

int main(void) {
    int N, K;
    long long M;
    scanf("%d %d %lld", &N, &K, &M);
    long long A[N];
    for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

    // 累積和
    long long S[N+1];
    S[0] = 0;
    for (int i = 0; i < N; i++) S[i+1] = S[i] + A[i];

    long long count = 0;
    for (int l = 1; l <= N-K+1; l++) {
        long long target = S[l-1] + M;
        int lo = l + K - 1, hi = N, ans = N + 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (S[mid] >= target) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        if (ans <= N) count += N - ans + 1;
    }

    printf("%lld\n", count);
    return 0;
}
