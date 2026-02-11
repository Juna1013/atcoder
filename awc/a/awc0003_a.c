#include <stdio.h>

int main(void) {
    int N, A;
    long long K, B;
    scanf("%d %lld", &N, &K);

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d %lld", &A, &B);
        long long score = A * B;
        if (K <= score) cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}
