#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);

    // cnt[s] = 0<x<y かつ x^2+y^2=s を満たす組の個数
    int *cnt = (int *)calloc((size_t)N + 1, sizeof(int));
    if (cnt == NULL) {
        return 1;
    }

    // x,y は最大でも sqrt(N)
    int limit = 0;
    while (1LL * (limit + 1) * (limit + 1) <= (long long)N) {
        limit++;
    }

    for (int x = 1; x <= limit; x++) {
        long long x2 = 1LL * x * x;
        for (int y = x + 1; y <= limit; y++) {
            long long s = x2 + 1LL * y * y;
            if (s > (long long)N) break;
            cnt[(int)s]++;
        }
    }

    int k = 0;
    for (int n = 1; n <= N; n++) {
        if (cnt[n] == 1) k++;
    }

    printf("%d\n", k);
    int first = 1;
    for (int n = 1; n <= N; n++) {
        if (cnt[n] == 1) {
            if (!first) putchar(' ');
            first = 0;
            printf("%d", n);
        }
    }
    putchar('\n');

    free(cnt);

    return 0;
}
