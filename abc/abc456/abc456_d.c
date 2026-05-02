#include <stdio.h>

#define MOD 998244353

int main(void) {
    char S[300001];
    scanf("%s", S);

    int n = 0;
    while (S[n] != '\0') n++;

    // dp[0] = a, dp[1] = b, dp[2] = c
    long long dp[3] = {0, 0, 0};

    for (int i = 0; i < n; i++) {
        int x = S[i] - 'a';
        long long total = (dp[0] + dp[1] + dp[2]) % MOD;
        dp[x] = (1 + total) % MOD;
    }

    long long ans = (dp[0] + dp[1] + dp[2]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
