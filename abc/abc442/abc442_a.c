#include <stdio.h>
#include <string.h>

int main(void) {
    char str[11];
    scanf("%s", str);

    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == 'i' || str[i] == 'j') count++;
    }

    printf("%d\n", count);
    return 0;
}
