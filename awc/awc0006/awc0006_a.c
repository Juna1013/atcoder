#include <stdio.h>

int main(void) {
    int N, L, W;
    scanf("%d %d %d", &N, &L, &W);
    int D;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &D);
        if ((L-W) <= D && D <= (L+W)) cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}
