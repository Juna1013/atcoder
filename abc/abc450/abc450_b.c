#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    // C[i][j]: 駅i→駅j のコスト
    long long C[101][101] = {0};

    // 上三角行列として読み込む
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            scanf("%lld", &C[i][j]);
        }
    }

    // a < b < c の全組み合わせをサーチ
    int found = 0;
    for (int a = 1; a <= N && !found; a++) {
        for (int b = a + 1; b <= N && !found; b++) {
            for (int c = b + 1; c <= N && !found; c++) {
                if (C[a][b] + C[b][c] < C[a][c]) {
                    found = 1;
                }
            }
        }
    }

    if (found) printf("Yes\n");
    else printf("No\n");

    return 0;
}
