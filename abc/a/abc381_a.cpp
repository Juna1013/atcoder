#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int count = 0;
    string S;
    cin >> N;
    cin >> S;

    int center = ((N + 1) / 2)- 1;

    if (N % 2 == 1) {
        if (S[center] == '/') {
            for (int i = 0; i < center; i++) {
                if (S[i] == '1' && S[center + 1 + i] == '2') {
                    count++;
                }
            }
        }
    }

    if (N % 2 == 1 && count == center) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

https://atcoder.jp/contests/abc381/submissions/me