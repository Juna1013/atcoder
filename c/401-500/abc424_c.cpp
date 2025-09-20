#include <iostream>
using namespace std;

const int MAXN = 200000;
const int MAXE = MAXN * 2;

int A[MAXN + 1], B[MAXN + 1];
bool learned[MAXN + 1];
int queue_[MAXN + 5];

int head[MAXN + 1];
int to[MAXE], nxt[MAXE];
int ecnt = 0;

void add_edge(int u, int v) {
    if (u == 0) return;
    to[ecnt] = v;
    nxt[ecnt] = head[u];
    head[u] = ecnt++;
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

    for (int i = 0; i <= N; i++) {
        head[i] = -1;
        learned[i] = false;
    }

    for (int i = 1; i <= N; i++) {
        add_edge(A[i], i);
        add_edge(B[i], i);
    }

    int f = 0, b = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] == 0 && B[i] == 0) {
            learned[i] = true;
            queue_[b++] = i;
        }
    }

    while (f < b) {
        int cur = queue_[f++];
        for (int e = head[cur]; e != -1; e = nxt[e]) {
            int idx = to[e];
            if (!learned[idx]) {
                learned[idx] = true;
                queue_[b++] = idx;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) if (learned[i]) ans++;
    cout << ans << endl;
}
