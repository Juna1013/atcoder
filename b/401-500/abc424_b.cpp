#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int cnt[11] = {0}; // 各々が解いた問題数をカウントする配列
    int results[11];   // 全問解いた人の番号を格納する配列
    int res_size = 0;  // resultsに入れた人数

    for (int i = 0; i < K; i++) {
        int A, B;
        cin >> A >> B; // 人Aが問題Bに正解した

        cnt[A]++;      // 人Aの解いた問題数を1増やす

        if (cnt[A] == M) { // 人Aが全問解いた場合
            results[res_size++] = A; // 達成順に記録
        }
    }

    // 全問解いた人を達成順に出力
    for (int i = 0; i < res_size; i++) {
        if (i > 0) cout << " ";
        cout << results[i];
    }
    if (res_size > 0) cout << endl;
}
