#include <iostream>
#include <string>
using namespace std;

int main() {
    // 入力
    int X;
    cin >> X;
    
    // Xを文字列に変換して各数字を抽出
    string s = to_string(X);
    int cnt = s.length();
    
    // 各数字を昇順にソート（バブルソート）
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                char tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
    
    // 先頭が0の場合、最初の0以外の数字と入れ替える
    if (s[0] == '0') {
        for (int i = 1; i < cnt; i++) {
            if (s[i] != '0') {
                char tmp = s[0];
                s[0] = s[i];
                s[i] = tmp;
                break;
            }
        }
    }
    
    // 結果を整数に変換して出力
    int answer = stoi(s);
    cout << answer << endl;

    return 0;
}
