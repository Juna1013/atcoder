#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S[N];
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<int> score(N, 0);

    // 投票回ごとに処理
    for (int j = 0; j < M; j++) {
        int x = 0, y = 0;
        for (int i = 0; i < N; i++) {
            if (S[i][j] == '0') x++;
            else y++;
        }

        if (x == 0 || y == 0) {
            // 全員に1点
            for (int i = 0; i < N; i++) score[i]++;
        } else if (x < y) {
            // 0を選んだ人に1点
            for (int i = 0; i < N; i++) {
                if (S[i][j] == '0') score[i]++;
            }
        } else {
            for (int i = 0; i < N; i++) {
                if (S[i][j] == '1') score[i]++;
            }
        }
    }

    // 最大得点を求める
    int maxScore = 0;
    for (int i = 0; i < N; i++) {
        if (score[i] > maxScore) maxScore = score[i];
    }

    // 昇順に番号を出力
    for (int i = 0; i < N; i++) {
        if (score[i] == maxScore) {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
}
