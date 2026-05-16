#include <stdio.h>
#include <string.h>

int min(int x, int y) {
    if (x < y) return x;
    else return y;
}

int main(void) {
    char S[500001];
    scanf("%s", S);
    int N = strlen(S);

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'C') {
            int left = i;
            int right = N - 1 - i;
            int ext = min(left, right);
            ans += ext + 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
