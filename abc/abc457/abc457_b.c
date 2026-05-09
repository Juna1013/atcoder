#include <stdio.h>

#define MAXN 200001

int main(void) {
    int N; scanf("%d", &N);
    int A[MAXN];
    int L[MAXN];
    int start[MAXN + 1]; start[1] = 0;

    for (int i = 1; i <= N; i++) {
        scanf("%d", &L[i]);
        start[i+1] = start[i] + L[i];
        for (int j = 1; j <= L[i]; j++) {
            scanf("%d", &A[start[i] + j - 1]);
        }
    }

    int X, Y;
    scanf("%d %d", &X, &Y);

    int ans = A[start[X] + Y - 1];
    printf("%d\n", ans);

    return 0;
}
