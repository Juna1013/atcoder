#include <stdio.h>

int main(void) {
    int T, X; 
    scanf("%d %d", &T, &X);
    int A; 
    
    scanf("%d", &A);
    int last = A;  /* 直前に保存された値 */
    printf("0 %d\n", last);  /* 時刻0は必ず保存 */

    for (int i = 1; i <= T; i++) {
        scanf("%d", &A);

        int diff;
        if (last - A < 0) {
            diff = A - last;
        } else {
            diff = last - A;
        }

        if (diff >= X) {
            printf("%d %d\n", i, A);
            last = A;  /* 保存されたときだけ更新 */
        }
    }
    return 0;
}
