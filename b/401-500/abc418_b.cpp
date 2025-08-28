#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();
    double ans = 0.0;

    // 部分文字列を列挙
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) { // 長さ3以上
            if (S[i] == 't' && S[j] == 't') {
                int len = j - i + 1;
                int cnt = 0;

                // 部分文字列内の 't' を数える
                for (int k = i; k <= j; k++) {
                    if (S[k] == 't') cnt++;
                }

                if (cnt >= 3) {
                    double rate = (cnt - 2) / (double)(len - 2);
                    if (rate > ans) ans = rate;
                }
            }
        }
    }

    cout.precision(17);
    cout << fixed << ans << endl;
    return 0;
}
