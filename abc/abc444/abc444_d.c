#include <stdio.h>

#define MAXV 200005

int cnt[MAXV]; // cnt[v]: A_i == vの個数
long long C[MAXV + 10]; // C[k]: k桁目に足される回数

int main(void) {
    int n;
    scanf("%d", &n);

    int max_a = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        cnt[a]++; // A_i == a の個数を記録
        if (a > max_a) max_a = a;
    }

    // 逆方向累積和でC[k]をつくる
    for (int k = max_a - 1; k >= 0; k--) {
        C[k] = C[k+1] + cnt[k+1]; // A_i > k の個数
    }

    // 繰り上がり処理
    int top = max_a - 1;
    for (int k = 0; k <= top || C[k] > 0; k++) {
        C[k+1] += C[k] / 10; // 繰り上げ分を上の桁へ
        C[k] = C[k] % 10; // 今の桁は余りだけ残す
        if (k + 1 > top && C[k+1] > 0) top = k + 1;
    }

    // 上位桁から出力
    for (int k = top; k >= 0; k--) {
        printf("%lld", C[k]);
    }
    printf("\n");

    return 0;
}
