#include <iostream>
using namespace std;

int main() {
    // 入力
    int A[3];
    for (int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    // 大きい順に並び替える
    int tmp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (A[j] < A[j + 1]) {
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }

    // 出力
    int answer = A[0] * 100 + A[1] * 10 + A[2];
    cout << answer << endl;

    return 0;
}