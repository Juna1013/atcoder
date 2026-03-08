#include <stdio.h>

int main(void) {
    // 入力
    int N;
    scanf("%d", &N);

    // 出力
    int answer = N * (N + 1) / 2;
    printf("%d\n", answer);

    return 0;
}
