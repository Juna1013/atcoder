#include <stdio.h>
#include <string.h>

#define MAXLEN 2000002

char A[MAXLEN], B[MAXLEN];
char sA[MAXLEN], sB[MAXLEN];

// 既約系を求める
// 結果はoutに、長さは*olenに格納
void reduce (char *s, char *out, int *olen) {
    int top = 0;
    for (int i = 0; s[i]; i++) {
        out[top++] = s[i];
        // 先頭4文字が(xx)なら置き換える
        while (top >= 4
            && out[top-4] == '('
            && out[top-3] == 'x'
            && out[top-2] == 'x'
            && out[top-1] == ')') {
                top -= 4;
                out[top++] = 'x';
                out[top++] = 'x';
        }
    }
    *olen = top;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s %s", A, B);
        int la, lb;
        reduce(A, sA, &la);
        reduce(B, sB, &lb);
        if (la == lb && strncmp(sA, sB, la) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
