#include <stdio.h>
#include <string.h>

int main(void) {
    char s[101]; scanf("%s", s);

    int cnt[26] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++) cnt[s[i] - 'a']++;

    int max = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > max) max = cnt[i];
    }

    for (int i = 0; i < len; i++) {
        if (cnt[s[i] - 'a'] < max) printf("%c", s[i]);
    }

    return 0;
}
