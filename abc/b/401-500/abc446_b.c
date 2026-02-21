#include <stdio.h>

int main(void) {
    int N, M; scanf("%d %d", &N, &M);
    int L;

    int taken[101] = {0};
    for (int i = 0; i < N; i++) {
        scanf("%d", &L);
        int X[L];
        for (int j = 0; j < L; j++) {
            scanf("%d", &X[j]);
        }

        int result = 0;
        for (int j = 0; j < L; j++) {
            if (!taken[X[j]]) {
                result = X[j];
                taken[X[j]] = 1;
                break;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
