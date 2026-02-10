#include <stdio.h>

int main(void) {
    // 入力
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    // 条件をみたす(l,r)の個数を数える
    int answer = 0;
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
            // l から r までの和を計算
            int sum = 0;
            for (int i = l; i <= r; i++) {
                sum += A[i];
            }
            
            // l から r までの全ての要素が sum の約数でないか確認
            int valid = 1;
            for (int i = l; i <= r; i++) {
                if (sum % A[i] == 0) {
                    valid = 0;
                    break;
                }
            }
            
            if (valid) answer++;
        }
    }

    // 出力
    printf("%d\n", answer);

    return 0;
}
