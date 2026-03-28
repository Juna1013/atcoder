#include <stdio.h>
#include <string.h>

int main(void) {
    char S[11];
    scanf("%s", S);

    int len = strlen(S);
    if (len % 5 == 0) {
        printf("Yes\n");
        return 0;
    } else {
        printf("No\n");
        return 0;
    }
}
