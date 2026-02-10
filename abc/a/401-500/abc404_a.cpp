#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int v[26];
    for (int i = 0; i < S.size(); i++) {
        v[S[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (v[i] == 0) {
            cout << char(i + 'a') << endl;
            return 0;
        }
    }
}
