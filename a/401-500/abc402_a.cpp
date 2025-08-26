#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    int counter = 0;

    for (int i = 0; i < N; i++) {
        if (isupper(S[i]) != 0) {
            cout << S[i];
        }
    }
    cout << endl;
}
