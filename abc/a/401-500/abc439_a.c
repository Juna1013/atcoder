#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int answer = 1;
    for (int i = 0; i < N; i++) answer *= 2;
    answer -= 2 * N;

    printf("%d\n", answer);

    return 0;
}
