#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    if (K <= N) {
        printf("0\n");
        return 0;
    }
    
    int cnt_been = 0;
    int cnt_year = N;
    while (1) {
        cnt_been += cnt_year;
        cnt_year++;
        if (K <= cnt_been) {
            printf("%d\n", cnt_year - N - 1);
            return 0;
        }
    }

    return 0;
}
