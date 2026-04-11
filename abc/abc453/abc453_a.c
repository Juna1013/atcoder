#include <stdio.h>

int main(void) {
    int N; scanf("%d", &N);
    char S[N + 1]; scanf("%s", S);
    char *p = S;

    while (*p == 'o') {
        p++;
    }

    printf("%s\n", p);
    return 0;
}
