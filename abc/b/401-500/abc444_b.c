#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        int tmp = i;
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == K) answer++;
    }

    printf("%d\n", answer);

    return 0;
}
