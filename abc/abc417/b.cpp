#include <iostream>
using namespace std;

int main() {
    // 入力
    int N, M;
    cin >> N >> M;
    int A[200], B[200];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    int len = N; // Aの長さ

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < len; j++) {
            if (A[j] == B[i]) {
                // A[j]を削除（前に詰める）
                for (int k = j; k < len - 1; k++) {
                    A[k] = A[k + 1];
                }
                len--;
                break; // 1回削除したら次の操作へ
            }
        }
    }

    // 出力
    for (int i = 0; i < len; i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}
