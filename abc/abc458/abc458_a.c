#include <stdio.h>
#include <string.h>

int main(void) {
    char S[31]; scanf("%s", S);
    int N; scanf("%d", &N);

    S[strlen(S) - N] = '\0';
    char *p = S + N;

    printf("%s\n", p);
    return 0;
}
