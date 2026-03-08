#include <stdio.h>

int main(void) {
    long long N, K;
    scanf("%lld %lld", &N, &K);
    long long A[N];
    for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

    // 左から右への伝播: L[i] = max(A[i], L[i-1] - K)
    long long L[N];
    L[0] = A[0];
    for (int i = 1; i < N; i++) {
        L[i] = L[i - 1] - K;
        if (L[i] < A[i]) L[i] = A[i];
    }

    // 右から左への伝播: R[i] = max(A[i], R[i+1] - K)
    long long R[N];
    R[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        R[i] = R[i + 1] - K;
        if (R[i] < A[i]) R[i] = A[i];
    }

    // B[i] = max(L[i], R[i]), 答え = sum(B[i] - A[i])
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long B = L[i] > R[i] ? L[i] : R[i];
        ans += B - A[i];
    }

    printf("%lld\n", ans);
    return 0;
}
