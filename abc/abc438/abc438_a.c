#include <stdio.h>

int main(void) {
    int D, F;
    scanf("%d %d", &D, &F);
    
    int days_to_next = D + 1 - F;
    int k = (days_to_next + 6) / 7;  // 上切り上げ
    int answer = F + 7 * k - D;
    
    printf("%d\n", answer);

    return 0;
}
