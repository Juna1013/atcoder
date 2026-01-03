#include <stdio.h>

// 桁数を求める
static int sumsq_digits(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

int main(void) {
    int N;
    scanf("%d", &N);

    // 置き換えを繰り返し、同じ値に戻ったらループなので終了
    // 最初の N は最大 2026 なので、それを含む範囲を持っておく
    int seen[3000] = {0};
    while (1) {
        if (N == 1) {
            printf("Yes\n");
            return 0;
        }
        if (seen[N]) {
            printf("No\n");
            return 0;
        }
        seen[N] = 1;
        N = sumsq_digits(N);
    }

    return 0;
}