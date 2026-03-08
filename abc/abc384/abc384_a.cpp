#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    char c1, c2;

    cin >> N >> c1 >> c2;
    cin >> S;

    for (int i = 0; i < N; i++) {
        if (S[i] != c1) {
            S[i] = c2;
        }
    }

    cout << S << endl;
}
