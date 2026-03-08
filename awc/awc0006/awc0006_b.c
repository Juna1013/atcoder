#include <stdio.h>

int main(void) {
    int N, K;
    long long T;
    scanf("%d %d %lld", &N, &K, &T);
    int D, R = 0;

    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &D, &R);
        if (R >= K * D) cnt += R;
    }

    if (T <= cnt) printf("Yes\n");
    else printf("No\n");

    return 0;
}
