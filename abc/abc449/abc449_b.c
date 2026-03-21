#include <stdio.h>

int main(void) {
    int H, W, Q;
    scanf("%d %d %d", &H, &W, &Q);

    // チョコレートを配列で表現
    int choco[100][100];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            choco[i][j] = 1;
        }
    }

    int cur_h = H, cur_w = W; // 現在の行数・列数

    for (int q = 0; q < Q; q++) {
        int type, n;
        scanf("%d %d", &type, &n);

        int count = 0;
        if (type == 1) { // 下R行を食べる
            for (int i = cur_h - n; i < cur_h; i++) {
                for (int j = 0; j < cur_w; j++) {
                    count += choco[i][j];
                    choco[i][j] = 0;
                }
            }
            cur_h -= n;
        } else { // 右C行を食べる
            for (int i = 0; i < cur_h; i++) {
                for (int j = cur_w - n; j < cur_w; j++) {
                    count += choco[i][j];
                    choco[i][j] = 0;
                }
            }
            cur_w -= n;
        }
        printf("%d\n", count);
    }

    return 0;
}
