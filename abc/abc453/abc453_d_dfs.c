#include <stdio.h>

#define MAXN 1000
#define MAXMOVE 5000000

int H, W;
char grid[MAXN][MAXN + 1];
int visited[MAXN][MAXN][5]; // [行][列][方向(0-3. 4=なし)]

// 方向: 0=U, 1=D, 2=L, 3=R
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char dname[] = "UDLR";

char path[MAXMOVE + 1];
int path_len = 0;

int dfs(int r, int c, int dir) {
    // 終了条件1: Gに到達
    if (grid[r][c] == 'G') return 1;

    // 終了条件2: 訪問済み
    if (visited[r][c][dir] == 1) return 0;
    visited[r][c][dir] = 1;

    // 4方向を試す
    for (int d = 0; d < 4; d++) {
        // oマス: 直前と同じ方向のみ
        if (grid[r][c] == 'o' && d != dir) continue;

        // xマス: 直前と同じ方向は禁止
        if (grid[r][c] == 'x' && d == dir) continue;

        int nr = r + dr[d];
        int nc = c + dc[d];

        // 範囲外・壁チェック
        if (nr < 0 || nr >= H || nc < 0 || nc >= W || grid[nr][nc] == '#') continue;

        path[path_len++] = dname[d];
        if (dfs(nr, nc, d)) return 1;
        path_len--; // バックトラック
    }
    return 0;
}

int main(void) {
    scanf("%d %d", &H, &W);
    int sr, sc;
    for (int i = 0; i < H; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'S') {
                sr = i;
                sc = j;
            }
        }
    }

    if (dfs(sr, sc, 4)) {
        printf("Yes\n");
        path[path_len] = '\0';
        printf("%s\n", path);
    } else {
        printf("No\n");
    }

    return 0;
}
