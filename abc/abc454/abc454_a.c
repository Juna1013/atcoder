#include <stdio.h>

int main(void) {
    int L, R;
    scanf("%d %d", &L, &R);

    int ans = R - L + 1;
    printf("%d\n", ans);

    return 0;
}