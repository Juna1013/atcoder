#include <stdio.h>
#include <string.h>

int main(void) {
    static char S[1000002];
    scanf("%s", S);

    long long a = 0, ab = 0, ans = 0;
    for (int i = 0; S[i]; i++) {
        if (S[i] == 'A') a++;
        else if (S[i] == 'B') {
            if (a > 0) {
                a--;
                ab++;
            } 
        }
        else {
            if (ab > 0) {
                ab--;
                ans++;
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
