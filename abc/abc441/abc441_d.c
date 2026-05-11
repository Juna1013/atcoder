#include <stdio.h>

#define MAXN 200001
#define MAXM 200001

// 隣接リスト（連結リスト形式）
int to[MAXM], ecost[MAXM], enext[MAXM], head[MAXN];
int edge_cnt = 0;

int N, M, L;
long long S, T;
int result[MAXN];

void add_edge(int u, int v, int c) {
    to[edge_cnt] = v;
    ecost[edge_cnt] = c;
    enext[edge_cnt] = head[u];
    head[u] = edge_cnt;
    edge_cnt++;
}

void dfs(int v, int step, long long cost) {
    if (step == 0) {
        if (cost >= S && cost <= T) result[v] = 1;
        return;
    }
    for (int e = head[v]; e != -1; e = enext[e]) {
        dfs(to[e], step - 1, cost + ecost[e]);
    }
}

int main(void) {
    scanf("%d %d %d %lld %lld", &N, &M, &L, &S, &T);

    for (int i = 0; i < N+1; i++) head[i] = -1;

    for (int i = 0; i < M; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        add_edge(u, v, c);
    }

    dfs(1, L, 0);

    int found = 0;
    for (int v = 1; v <= N; v++) {
        if (result[v]) {
            if (found) printf(" ");
            printf("%d", v);
            found = 1;
        }
    }

    printf("\n");
    return 0;
}
