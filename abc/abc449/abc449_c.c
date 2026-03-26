// 解法：スライディングウィンドウ
#include <stdio.h>
#include <string.h>

int main(void) {
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    r++;
    char s[n+1];
    scanf("%s", s);
    long long ans = 0;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        if (i >= l) cnt[s[i-l] - 'a']++;
        if (i >= r) cnt[s[i-r] - 'a']--;
        ans += cnt[s[i] - 'a'];
    }
    printf("%lld\n", ans);

    return 0;
}
