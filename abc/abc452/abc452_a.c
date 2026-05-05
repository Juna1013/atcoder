#include <stdio.h>

int main(void) {
    int M, D;
    scanf("%d %d", &M, &D);

    /* 3〜9の奇数月（五節句の月）かどうか */
    int is_sekku_month = M % 2 == 1 && M >= 3 && M <= 9;
    int ok = (M == 1 && D == 7) || (is_sekku_month && D == M);

    if (ok) printf("Yes\n");
    else printf("No\n");
    
    return 0;
}
