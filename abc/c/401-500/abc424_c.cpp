#include <iostream>
using namespace std;

const int MAXN = 200000; // 最大スキル数
const int MAXE = MAXN * 2; // 辺の最大数（各スキルに最大2つの前提がある）

int A[MAXN + 1], B[MAXN + 1]; // 各スキルの前提スキル
bool learned[MAXN + 1]; // 習得済みかどうか
int queue_[MAXN + 5]; // BFS用キュー

int head[MAXN + 1]; // 各頂点の隣接リストの先頭
int to[MAXE], nxt[MAXE]; // 隣接リスト用配列
int ecnt = 0; // 辺の数

// グラフに辺を追加：uを取得したらvを習得可能になる
void add_edge(int u, int v) {
    if (u == 0) return; // 0は前提なしなのでスキップ
    to[ecnt] = v; // 辺の行き先を記録
    nxt[ecnt] = head[u]; // 既存リストの前に繋ぐ
    head[u] = ecnt++; // 新しい先頭にする
}

int main() {
    int N;
    cin >> N;

    // 各スキルの前提(A, B)を入力
    for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

    // 初期化
    for (int i = 0; i <= N; i++) {
        head[i] = -1;
        learned[i] = false;
    }

    // グラフを構築（前提スキル → そのスキル）
    for (int i = 1; i <= N; i++) {
        add_edge(A[i], i);
        add_edge(B[i], i);
    }

    int f = 0, b = 0; // BFSのfront/backインデックス
    // すでに習得済み(0, 0)のスキルをキューに入れる
    for (int i = 1; i <= N; i++) {
        if (A[i] == 0 && B[i] == 0) {
            learned[i] = true;
            queue_[b++] = i;
        }
    }

    // BFSで習得可能なスキルを広げる
    while (f < b) {
        int cur = queue_[f++];
        for (int e = head[cur]; e != -1; e = nxt[e]) {
            int idx = to[e];
            if (!learned[idx]) { // まだ習得してないなら
                learned[idx] = true; // 習得済みにして
                queue_[b++] = idx; // 次の探索候補に加える
            }
        }
    }

    // 習得できたスキルの総数をカウント
    int ans = 0;
    for (int i = 1; i <= N; i++) if (learned[i]) ans++;
    cout << ans << endl;
}
