#include <stdio.h>
#include <string.h>

int main(void) {
    // 入力
    char S[10];
    scanf("%s", S);

    // 中央の文字を削除して出力
    int N = strlen(S);
    int center = N / 2;
    for (int i = 0; i < N; i++) {
        if (i != center) printf("%c", S[i]);
    }
    printf("\n");

    return 0;
}

