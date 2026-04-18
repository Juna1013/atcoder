#include <stdio.h>

#define MAXN 300001

int to[MAXN], next_e[MAXN], head[MAXN], visited[MAXN];

void dfs (int v) {
    visited[v] = 1;
    for (int e = head[v]; e != -1; e = next_e[e]) {
        int u = to[e];
        if (visited[u] == 0) {
            dfs(u);
        }
    }
}

int main(void) {
    int N, M, A, B;
    scanf("%d %d", &N, &M);

    // head を全部 -1 で初期化
    for (int i = 0; i < N; i++) head[i] = -1;

    // M本の辺を読み込んで隣接リストに追加
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        A--; B--; // 0-indexed に変換
        to[i] = B;
        next_e[i] = head[A];
        head[A] = i;
    }

    dfs(0);

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i] == 1) count++;
    }
    printf("%d\n", count);

    return 0;
}