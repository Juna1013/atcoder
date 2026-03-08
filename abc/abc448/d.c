// 解法：深さ優先探索 + バックトラッキング
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200005

int N;
int A[MAXN];
int compressed[MAXN]; // 座標圧縮後の値
int ans[MAXN]; // 0 = No, 1 = Yes
int cnt[MAXN]; // 現在パス上の各値の出現回数

// 隣接リスト
int head[MAXN], to[2*MAXN], nxt[2*MAXN], ecnt;

// 隣接リストに辺を追加する
void add_edge(int u, int v) {
    ecnt++;
    to[ecnt] = v;
    nxt[ecnt] = head[u];
    head[u] = ecnt;
}

int sorted_A[MAXN], unique_n;

int cmp_int(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

// 座標圧縮：valが何番目か（2分探索）
int compress(int val) {
    int lo = 0, hi = unique_n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (sorted_A[mid] < val) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

void dfs(int v, int parent, int has_dup) {
    int c = compressed[v];
    cnt[c]++;
    int new_dup = has_dup || (cnt[c] >= 2);
    ans[v] = new_dup;

    for (int e = head[v]; e; e =nxt[e]) {
        int u = to[e];
        if (u == parent) continue;
        dfs(u, v, new_dup);
    }

    cnt[c]--; // バックトラック
}

int main(void) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        sorted_A[i-1] = A[i];
    }

    // 座標圧縮
    qsort(sorted_A, N, sizeof(int), cmp_int);
    unique_n = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 || sorted_A[i] != sorted_A[i-1]) {
            sorted_A[unique_n++] = sorted_A[i];
        }
    }
    for (int i = 1; i <= N; i++) {
        compressed[i] = compress(A[i]);
    }

    for (int i = 0; i < N-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    dfs(1, 0, 0);

    for (int i = 1; i <= N; i++) {
        printf("%s\n", ans[i] ? "Yes" : "No");
    }

    return 0;
}
