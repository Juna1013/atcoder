#include <stdio.h>

int main(void) {
    int T; scanf("%d", &T);

    while (T--) {
        int N, D;
        scanf("%d %d", &N, &D);

        int A[200001], B[200001], egg[200001];

        for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
        for (int i = 1; i <= N; i++) scanf("%d", &B[i]);

        // egg[i] = i日目に仕入れた卵の残数
        int front = 1; // まだ残っている最も古い日

        for (int i = 1; i <= N; i++) {
            // 朝：仕入れ
            egg[i] = A[i];

            // 昼：B[i]個を古い順に消費
            int use = B[i];
            while (use > 0) {
                if (egg[front] <= use) {
                    use -= egg[front];
                    egg[front] = 0;
                    front++;
                } else {
                    egg[front] -= use;
                    use = 0;
                }
            }

            // 夜：仕入れからD日以上経過した卵を処分
            while (front <= i && front <= i - D) {
                egg[front] = 0;
                front++;
            }
        }

        // 残った卵を合計
        long long ans = 0;
        for (int i = front; i <= N; i++) ans += egg[i];
        printf("%lld\n", ans);
    }

    return 0;
}
