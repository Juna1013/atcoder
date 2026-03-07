// 解法：K<5より小さいボール6個のみを把握して処理
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx; // ボール番号
} Ball;

int cmp_asc(const void *a, const void *b) {
    return ((Ball *)a)->val - ((Ball *)b)->val;
}

int main(void) {
    int N, Q;
    scanf("%d %d", &N, &Q);

    Ball balls[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &balls[i].val);
        balls[i].idx = i+1;
    }

    // 上位6個を昇順で保持
    int top;
    if (N < 6) top = N;
    else top = 6;
    qsort(balls, N, sizeof(Ball), cmp_asc);

    for (int q = 0; q < Q; q++) {
        int K;
        scanf("%d", &K);
        int B[K];
        for (int i = 0; i < K; i++) scanf("%d", &B[i]);

        // 上位6個の中でBに含まれないものを探す
        for (int i = 0; i < top; i++) {
            int removed = 0;
            for (int j = 0; j < K; j++) {
                if (balls[i].idx == B[j]) {
                    removed = 1;
                    break;
                }
            }
            if (!removed) {
                printf("%d\n", balls[i].val);
                break;
            }
        }
    }

    return 0;
}
