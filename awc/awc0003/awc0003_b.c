#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int cnt = 0;
    char L, R, L_tmp, R_tmp = ' ';
    scanf(" %c %c", &L_tmp, &R_tmp);
    for (int i = 0; i < N - 1; i++) {
        scanf(" %c %c", &L, &R);
        if (R_tmp == L) cnt++;
        L_tmp = L; R_tmp = R;
    }

    printf("%d\n", cnt);
    return 0;
}
