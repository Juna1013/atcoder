#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[200005];
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    int stack[200005]; // スタック内の値
    int count[200005]; // 各位置での連続個数
    int top = 0;

    for (int i = 0; i < N; i++) {
        stack[top] = A[i];
        count[top] = 1;
        top++;

        // 削除チェック
        while (top >= 4 && stack[top - 1] == stack[top - 2] && 
               stack[top - 2] == stack[top - 3] && stack[top - 3] == stack[top - 4]) {
            top -= 4;
        }
    }

    printf("%d\n", top);

    return 0;
}
