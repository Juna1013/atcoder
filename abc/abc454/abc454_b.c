#include <stdio.h>

int main(void) {
    int N, M, F;
    scanf("%d %d", &N, &M);

    int ans[M];
    for (int i = 0 ; i < M; i++) ans[i] = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &F);
        ans[F-1]++;
    }

    // 質問1の判定
    for (int i = 0; i < M; i++) {
        if (ans[i] >= 2) {
            printf("No\n");
            break;
        }
        if (i == M-1) {
            printf("Yes\n");
            break;
        }
    }

    // 質問2の判定
    for (int i = 0; i < M; i++) {
        if (ans[i] == 0) {
            printf("No\n");
            break;
        } 
        if (i == M-1) {
            printf("Yes\n");
            break;
        }
    }

    return 0;
}
