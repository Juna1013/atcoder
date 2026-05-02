#include <stdio.h>

#define MOD 998244353

int main(void) {
    char S[300001];
    scanf("%s", S);

    int n = 0;
    while (S[n] != '\0') n++;

    long long ans = 0;
    long long f = 1; // f(j): jでおわる有効な部分文字列の個数

    ans = 1; // j=0の分
    for (int j = 1; j < n; j++) {
        if (S[j] != S[j-1]) {
            f = f + 1;
        } else {
            f = 1;
        }
        ans = (ans + f) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}
