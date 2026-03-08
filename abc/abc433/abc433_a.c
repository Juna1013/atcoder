#include <stdio.h>

int main(void) {
    // 入力
    int X, Y, Z;
    scanf("%d %d %d", &X, &Y, &Z);
    
    // タイミングが存在するか探索
    int A = X - 1;
    int B = Y - 1;
    for (int i = 0; i < 100; i++) {
        A++;
        B++;
        if (A == B * Z) {
            printf("Yes\n");
            return 0;
        }
    }
    
    // 出力
    printf("No\n");
    return 0;   
}
