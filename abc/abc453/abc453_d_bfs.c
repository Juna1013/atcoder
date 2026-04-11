#include <stdio.h>
#include <string.h>

#define MAXN 1000
#define MAXSTATES (MAXN * MAXN * 5)

int H, W;
char grid[MAXN][MAXN + 1];

// 方向: 0=U, 1=D, 2=L, 3=R, 4=なし（スタート）
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char dname[] = "UDLR";

int visited[MAXN][MAXN][5];

// 親ポインタ: どの状態から来たか
int par_r[MAXN][MAXN][5];
int par_c[MAXN][MAXN][5];
int par_dir[MAXN][MAXN][5];

typedef struct { int r, c, dir; } State;
State queue[MAXSTATES];
char path[MAXSTATES];

int main(void) {
    scanf("%d %d", &H, &W);
    int sr, sc, gr, gc;
    for (int i = 0; i < H; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            if (grid[i][j] == 'G') {
                gr = i;
                gc = j;
            }
        }
    }

    // BFS初期化
    int head = 0, tail = 0;
    queue[tail++] = (State){sr, sc, 4};
    visited[sr][sc][4] = 1;

    int found = 0, fdir = -1;

    while (head < tail && !found) {
        State cur = queue[head++];
        int r = cur.r, c = cur.c, dir = cur.dir;

        for (int d = 0; d < 4; d++) {
            // o, x の条件チェック
            if (grid[r][c] == 'o' && dir != 4 && d != dir) continue;
            if (grid[r][c] == 'x' && d == dir) continue;

            int nr = r + dr[d];
            int nc = c + dc[d];

            // 範囲外・壁チェック
            if (nr < 0 || nr >= H || nc < 0 || nc >= W || grid[nr][nc] == '#') continue;

            if (visited[nr][nc][d]) continue;
            visited[nr][nc][d] = 1;

            // 親ポインタを記録
            par_r[nr][nc][d] = cur.r;
            par_c[nr][nc][d] = cur.c;
            par_dir[nr][nc][d] = cur.dir;

            queue[tail++] = (State){nr, nc, d};

            if (nr == gr && nc == gc) {
                found = 1;
                fdir = d;
                break;
            }
        }
    }

    if (!found) {
        printf("No\n");
        return 0;
    }

    // パス復元: ゴールからスタートへ逆順に辿る
    int plen = 0;
    int r = gr, c = gc, dir = fdir;
    while (!(r == sr && c == sc)) {
        path[plen++] = dname[dir];
        int pr = par_r[r][c][dir];
        int pc = par_c[r][c][dir];
        int pd = par_dir[r][c][dir];
        r = pr; c = pc; dir = pd;
    }

    // 逆順をなおす
    for (int i = 0; i < plen / 2; i++) {
        char tmp = path[i];
        path[i] = path[plen - 1 - i];
        path[plen - 1 - i] = tmp;
    }
    path[plen] = '\0';

    printf("Yes\n%s\n", path);
    return 0;
}
