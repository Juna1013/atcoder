#include <iostream>
using namespace std;

int main() {
    // 入力
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    string subs[100];
    int counts[100];
    int numSubs = 0;

    for (int i = 0; i <= N - K; i++) {
        string t = "";
        for (int j = 0; j < K; j++) {
            t = t + S[i + j];
        }

        int found = -1;
        for (int j = 0; j < numSubs; j++) {
            if (subs[j] == t) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            subs[numSubs] = t;
            counts[numSubs] = 1;
            numSubs++;
        } else {
            counts[found]++;
        }
    }

    // 最大出現回数
    int maxCount = 0;
    for (int i = 0; i < numSubs; i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
        }
    }

    // 辞書順に並べる
    for (int i = 0; i < numSubs - 1; i++) {
        for (int j = i + 1; j < numSubs; j++) {
            if (subs[j] < subs[i]) {
                string tmpS = subs[i];
                subs[i] = subs[j];
                subs[j] = tmpS;

                int tmpC = counts[i];
                counts[i] = counts[j];
                counts[j] = tmpC;
            }
        }
    }

    // 出力
    cout << maxCount << endl;

    for (int i = 0; i < numSubs; i++) {
        if (counts[i] == maxCount) {
            cout << subs[i];
            int hasNext = 0;
            for (int j = i + 1; j < numSubs; j++) {
                if (counts[j] == maxCount) {
                    hasNext = 1;
                    break;
                }
            }
            if (hasNext) cout << " ";
        }
    }
    cout << endl;
}
