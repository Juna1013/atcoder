# ABC439 C（良い整数の列挙）: 実装で間違えていた点まとめ

対象: `c/401-500/abc439_c.c` の最初の実装

## 問題の要点

正整数 `n` が「良い整数」であるとは、

- `0 < x < y` かつ `x^2 + y^2 = n`
- を満たす整数組 `(x, y)` が **ちょうど 1 つ**存在する

こと。

入力として `N (1<=N<=10^7)` が与えられるので、`n <= N` の良い整数をすべて昇順に列挙し、

- 1行目: 個数 `k`
- 2行目: 良い整数を昇順に並べた列（`k=0` なら空行）

を出力する。

## 間違っていた点（なぜ出力が違うか）

### 1) `N` だけを調べていて、`n<=N` 全体を列挙していない

最初の実装は `i*i + j*j == N` を見ており、

- `N` 自身が良い整数かどうか

しか判定していません。

しかし問題は **`N 以下の良い整数を全列挙`** なので、
`n=1..N` のそれぞれについて `(x,y)` の個数を数える必要があります。

### 2) 計算量が `O(N^2)` になっていて制約に合わない

最初の実装は概ね

- `i = 0..N-1`
- `j = i..N-1`

を回しており、最悪で約 `N^2/2` 回のループです。
`N=10^7` では現実的に実行不可能です。

### 3) `int A[N];` が巨大なスタック配列（環境によっては落ちる）

`N=10^7` だと `int A[N]` はおよそ 40MB で、
環境によってはスタックオーバーフロー等で不正終了する可能性があります。

### 4) 出力内容が仕様と一致していない

最初の実装は `A[i]++` のように `i` ごとに数えており、
「良い整数 `n` の列挙」に必要な情報（各 `n` の表現数）が取れていません。

## 修正方針（今回の解法）

`n` を直接全探索するのではなく、

- `0 < x < y`
- `x^2 + y^2 <= N`

を満たす `(x,y)` を列挙して、和 `s = x^2 + y^2` に対して `cnt[s]++` します。

- `x,y` の最大は `sqrt(N)` なので、探索範囲は `O(sqrt(N)^2)` で済む
- 最後に `cnt[n] == 1` の `n` を昇順で出力する

これにより、サンプル `N=10,1,50` は期待どおりの出力になります。

## コード全文比較（Before / After）

### Before（最初の実装）

```c
#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) A[i] = 0;
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (i*i + j*j == N) {
                cnt++;
                A[i]++;
            }
        }
    }

    printf("%d\n", cnt);
    for (int i = 0; i < N; i++) {
        if (A[i] == 1) printf("%d ", i);
    }
    printf("\n");

    return 0;
}
```

### After（修正版）

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);

    // cnt[s] = 0<x<y かつ x^2+y^2=s を満たす組の個数
    int *cnt = (int *)calloc((size_t)N + 1, sizeof(int));
    if (cnt == NULL) {
        return 1;
    }

    // x,y は最大でも sqrt(N)
    int limit = 0;
    while (1LL * (limit + 1) * (limit + 1) <= (long long)N) {
        limit++;
    }

    for (int x = 1; x <= limit; x++) {
        long long x2 = 1LL * x * x;
        for (int y = x + 1; y <= limit; y++) {
            long long s = x2 + 1LL * y * y;
            if (s > (long long)N) break;
            cnt[(int)s]++;
        }
    }

    int k = 0;
    for (int n = 1; n <= N; n++) {
        if (cnt[n] == 1) k++;
    }

    printf("%d\n", k);
    int first = 1;
    for (int n = 1; n <= N; n++) {
        if (cnt[n] == 1) {
            if (!first) putchar(' ');
            first = 0;
            printf("%d", n);
        }
    }
    putchar('\n');

    free(cnt);

    return 0;
}
```

## 差分のポイント（要約）

- Before は「`N` だけ」かつ「`O(N^2)`」で、問題の要求と制約に合いません。
- After は「`x^2+y^2` の和 `s` ごとに回数を数える」ことで、`n<=N` の全列挙を正しく行います。
