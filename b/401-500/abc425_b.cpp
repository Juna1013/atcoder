#include <iostream>
using namespace std;

int main() {
    // 入力
    int N;
    cin >> N;
    int A[20];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // A[i] != -1 のカウント
    int used[20] = {0};
    for (int i = 0; i < N; i++) {
        if (A[i] != -1) {
            if (used[A[i]]) {
                cout << "No" << endl;
                return 0;
            }
            used[A[i]] = 1;
        }
    }

    // 未使用の数を埋める
    int unused[20];
    int unused_size = 0;
    for (int x = 1; x <= N; x++) {
        if (!used[x]) {
            unused[unused_size++] = x;
        }
    }

    // 出力
    cout << "Yes" << endl;
    int idx = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] != -1) {
            cout << A[i] << " ";
        } else {
            cout << unused[idx++] << " ";
        }
    }
    cout << endl;
}
