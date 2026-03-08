#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char S[100];
    scanf("%s", S);

    S[0] = tolower(S[0]);
    printf("Of%s\n", S);

    return 0;
}
