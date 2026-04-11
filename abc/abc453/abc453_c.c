// 解法：ビット全探索
#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int L[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        double pos = 0.5;
        int count = 0;
        for (int i = 0; i < N; i++) {
            int dir = (mask >> i) & 1;
            double prev = pos;
            if (dir == 0) {
                pos += L[i];
            } else {
                pos -= L[i];
            }
            // ここで0を通り過ぎたか判定
            if (prev * pos < 0) {
                count++;
            }
        }
        // countの最大値を更新
        if (count > ans) {
            ans = count;
        }
    }

    printf("%d\n", ans);
    return 0;
}