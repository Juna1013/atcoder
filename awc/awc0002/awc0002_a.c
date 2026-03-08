#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);
    int A[N];
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    for (int i = 0; i < N; i++) {
        if (A[i] == K) {
            printf("%d\n", i+1);
            return 0;
        }
    }

    int unexit = -1;
    printf("%d\n", unexit);
    return 0;
}
