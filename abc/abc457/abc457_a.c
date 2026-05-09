#include <stdio.h>

int main(void) {
    int N; scanf("%d", &N);
    int A[N]; for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    int X; scanf("%d", &X);

    int ans = A[X - 1];
    printf("%d\n", ans);

    return 0;
}
