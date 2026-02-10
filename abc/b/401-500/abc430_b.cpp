#include <iostream>
using namespace std;

int main() {
    // 入力
    int N, M;
    cin >> N >> M;
    char S[10][10];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    // パターンの保存
    char patterns[100][100];
    int patternCount = 0; // 現在保存されている異なるパターンの数

    // すべての部分領域を探索
    for (int top = 0; top <= N - M; top++) {
        for (int left = 0; left <= N - M; left++) {
            // M×M領域を1次元化して保存
            char temp[100]; // 一時的に保存
            int idx = 0;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    temp[idx++] = S[top + i][left + j]; // 領域のマスを順に記録
                }
            }
            temp[idx] = '\0';

            // 既存のパターンと同じかチェック
            bool same = false;
            for (int p = 0; p < patternCount; p++) {
                bool equal = true;
                for (int k = 0; k < idx; k++) {
                    if (patterns[p][k] != temp[k]) { // 異なるパターンの条件
                        equal = false;
                        break;
                    }
                }
                // 同一パターンと判断
                if (equal) {
                    same = true;
                    break;
                }
            }

            // 新しいパターンの保存
            if (!same) {
                // tempの内容をpatterns[patternCount]にコピー
                for (int k = 0; k <= idx; k++) {
                    patterns[patternCount][k] = temp[k];
                }
                patternCount++; // 新しい模様
            }
        }
    }

    // 出力
    cout << patternCount << endl;
    return 0;
}
