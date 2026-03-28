#include <stdio.h>

int main(void) {
    int N, M, A, B;
    scanf("%d %d", &N, &M);

    int dep_now[M + 1], dep_next[M + 1];
    for (int i = 0; i <= M; i++) {
        dep_now[i] = 0;
        dep_next[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A, &B);
        dep_now[A]++;
        dep_next[B]++;
    }

    for (int i = 1; i <= M; i++) {
        int answer = dep_next[i] - dep_now[i];
        printf("%d\n", answer);
    }

    return 0;
}
