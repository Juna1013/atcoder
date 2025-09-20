#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int cnt[11] = {0};
    int results[11];
    int res_size = 0;

    for (int i = 0; i < K; i++) {
        int A, B;
        cin >> A >> B;

        cnt[A]++;

        if (cnt[A] == M) {
            results[res_size++] = A;
        }
    }

    for (int i = 0; i < res_size; i++) {
        if (i > 0) cout << " ";
        cout << results[i];
    }
    if (res_size > 0) cout << endl;
}
