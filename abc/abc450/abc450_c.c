// 解法：深さ優先探索
#include <stdio.h>

int H, W;
char S[1001][1002];
int visited[1001][1001];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

void dfs(int i, int j) {
    visited[i][j] = 1; // 訪問済みにする

    for (int d = 0; d < 4; d++) {
        int ni = i + di[d];
        int nj = j + dj[d];

        if (0 <= ni && ni < H && 0 <= nj && nj < W && S[ni][nj] == '.' && visited[ni][nj] == 0) {
            dfs(ni, nj);
        }
    }
}

int main(void) {
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++) {
        scanf("%s", S[i]); // 1行ずつ文字列として読む
    }

    // 上端・下端
    for (int j = 0; j < W; j++) {
        if (S[0][j] == '.') dfs(0, j);
        if (S[H-1][j] == '.') dfs(H-1, j);
    }

    // 左端・右端
    for (int i = 0; i < H; i++) {
        if (S[i][0] == '.') dfs(i, 0);
        if (S[i][W-1] == '.') dfs(i, W-1);
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (visited[i][j] == 0 && S[i][j] == '.') {
                ans++;
                dfs(i, j); // この島全体を訪問済みにする
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
