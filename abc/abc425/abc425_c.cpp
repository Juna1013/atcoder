#include <iostream>
using namespace std;

const int MAXN = 200000;

int main() {
    int N, Q;
    cin >> N >> Q;
    long long A[MAXN];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long prefix[2 * MAXN + 1];
    prefix[0] = 0;
    for (int i = 0; i < 2 * N; i++) {
        prefix[i + 1] = prefix[i] + A[i % N];
    }

    int offset = 0;
    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;
        if (type == 1) {
            int c;
            cin >> c;
            offset = (offset + c) % N;
        } else {
            int l, r;
            cin >> l >> r;
            int start = offset + (l - 1);
            int len = r - l + 1;
            long long ans = prefix[start + len] - prefix[start];
            cout << ans << endl;
        }
    }
}
