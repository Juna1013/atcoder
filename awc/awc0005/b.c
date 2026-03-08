#include <stdio.h>

int main(void) {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    int S[N]; for (int i = 0;  i < N; i++) scanf("%d", &S[i]);
    
    int P, V = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &P, &V);
        S[P-1] = V;
    }

    int cnt = 0;
    for (int j = 0; j < N; j++) {
        if (S[j] < K) cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}
