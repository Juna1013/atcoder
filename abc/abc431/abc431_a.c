#include <stdio.h>

int main(void) {
    // 入力
    int H, B;
    scanf("%d %d", &H, &B);

    // 重量の比較
    int answer = 0;
    if (H > B) answer = H - B;

    // 出力
    printf("%d\n", answer);

    return 0;
}
