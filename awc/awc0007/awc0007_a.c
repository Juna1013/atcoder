#include <stdio.h>

int main(void) {
    int N, M; scanf("%d %d", &N, &M);
    int E[N], C[M];
    for (int i = 0; i < N; i++) scanf("%d", &E[i]);
    for (int j = 0; j < M; j++) scanf("%d", &C[j]);

    // 燃費係数が最小のトラックを選ぶ
    int min_e = E[0];
    for (int i = 1; i < N; i++) {
        if (E[i] < min_e) min_e = E[i];
    }

    // 全区間の距離の合計を求める
    long long sum_c = 0;
    for (int j = 0; j < M; j++) {
        sum_c += C[j];
    }

    printf("%lld\n", (long long)min_e * sum_c);
    return 0;
}
