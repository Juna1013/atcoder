#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);
    char S[N - 1];
    scanf("%s", &S);

    int length = strlen(S);

    int loop = N - length;
    for (int i = 0; i < loop; i++) printf("o");
    printf("%s\n", S);

    return 0;
}
