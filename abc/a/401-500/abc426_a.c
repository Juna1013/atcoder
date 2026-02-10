#include <stdio.h>
#include <string.h>

int getVersion(char *s) {
    if (strcmp(s, "Ocelot") == 0) return 1;
    if (strcmp(s, "Serval") == 0) return 2;
    if (strcmp(s, "Lynx") == 0) return 3;
    return 0;
}

int main(void) {
    // 入力
    char X[10], Y[10];
    scanf("%s %s", X, Y);

    // バージョンを数値化して比較
    int x = getVersion(X);
    int y = getVersion(Y);

    // 比較して出力
    if (x >= y) printf("Yes\n");
    else printf("No\n");

    return 0;
}
