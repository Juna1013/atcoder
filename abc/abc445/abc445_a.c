#include <stdio.h>
#include <string.h>

int main(void) {
    char S[10];
    scanf("%s", S);

    int len = strlen(S);
    if (S[0] == S[len-1]) printf("Yes\n");
    else printf("No\n");

    return 0;
}
