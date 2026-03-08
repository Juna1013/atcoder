#include <stdio.h>
#include <string.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    // 各研究室のテーマを保存
    int M[500];
    char W[500][50][21]; // W[研究室][テーマ番号][文字列]

    for (int i = 0; i < N; i++) {
        scanf("%d", &M[i]);
        for (int j = 0; j < M[i]; j++) {
            scanf("%s", W[i][j]);
        }
    }

    // 全ペア(i,j)について共通テーマ数を数える
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int common = 0;
            for (int a = 0; a < M[i]; a++) {
                for (int b = 0; b < M[j]; b++) {
                    if (strcmp(W[i][a], W[j][b]) == 0) {
                        common++;
                    }
                }
            }
            if (common >= K) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
