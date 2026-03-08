#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    static char s[300001],t[300001];
    scanf("%s %s", s, t);
    int slen = strlen(s), tlen = strlen(t);
    int si = 0, ti = 0;

    while (si < slen || ti < tlen) {
        while (si < slen && s[si] == 'A') si++;
        while (ti < tlen && t[ti] == 'A') ti++;
        if (si >= slen && ti >= tlen) break;
        if (si >= slen || ti >= tlen || s[si] != t[ti]) {
            printf("-1\n");
            return 0;
        }
        si++; ti++;
    }

    long long ans = 0;
    si = ti = 0;
    while (1) {
        int sa = 0, ta = 0;
        while (si < slen && s[si] == 'A') { sa++; si++; }
        while (ti < tlen && t[ti] == 'A') { ta++; ti++; }
        ans += abs(sa - ta);
        if (si >= slen && ti >= tlen) break;
        si++; ti++;
    }

    printf("%lld\n", ans);
    return 0;
}