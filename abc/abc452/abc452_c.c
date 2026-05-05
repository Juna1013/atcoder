#include <stdio.h>
#include <string.h>

int N, M;
int A[10], B[10];
char S[200000][11];
int can[10][26] = {0}; // can[i][c] = 肋骨iに文字cが使えるか

int main(void) {
    // 入力
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d %d", &A[i], &B[i]);
    scanf("%d", &M);
    for (int j = 0; j < M; j++) scanf("%s", S[j]);

    // クエリのループの前に計算する
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            if (strlen(S[k]) == A[i]) {
                can[i][S[k][B[i] - 1] - 'a'] = 1;
            }
        }
    }

    for (int j = 0; j < M; j++) {
        // 文字列の長さの確認
        if (strlen(S[j]) != N) {
            printf("No\n");
            continue;
        }

        int count = 0;
        for (int i = 0; i < N; i++) {
            // 肋骨iの条件を満たすS_kを探す
                if (can[i][S[j][i] - 'a']) count++;
        }

        if (count == N) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
