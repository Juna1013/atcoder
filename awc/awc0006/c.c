#include <stdio.h>

int main(void) {
    int N, M, D;
    scanf("%d %d %d", &N, &M, &D);
    int T[N]; for (int i = 0; i < N; i++) scanf("%d", &T[i]);

    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        if (T[i] > M) {
            cnt += (T[i] - M + D - 1) / D;
        }
    }

    printf("%lld\n", cnt);
    return 0;
}
