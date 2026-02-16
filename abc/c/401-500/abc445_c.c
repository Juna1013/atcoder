#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int A[N], ans[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        ans[i] = -1;
    }

    for (int s = 0; s < N; s++) {
        if (ans[s] != -1) continue;
        int x = s;
        while (A[x] != x+1) x = A[x] - 1;
        int y = s;
        while (ans[y] == -1) {
            ans[y] = x+1;
            y = A[y] - 1;
        }
    }

    for (int s = 0; s < N; s++) {
        printf("%d", ans[s]);
        if (s < N-1) printf(" ");
    }
    printf("\n");

    return 0;
}
