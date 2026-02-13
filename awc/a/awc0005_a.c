#include <stdio.h>

int main(void) {
    long long N, K, P;
    scanf("%lld %lld", &N, &K);

    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &P);
        if (P % K == 0) cnt += P;
    }

    printf("%lld\n", cnt);
    return 0;
}
