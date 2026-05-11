#include <stdio.h>

int deg[200001];

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        deg[a]++; deg[b]++;
    }

    for (int i = 1; i <= N; i++) {
        long long k = N - 1 - deg[i];
        long long ans = k * (k-1) * (k-2) / 6;
        if (i < N) printf("%lld ", ans);
        else printf("%lld\n", ans);
    }

    return 0;
}
