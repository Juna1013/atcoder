#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D;
    string S;
    cin >> N >> D;
    cin >> S;

    int count = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == '@') {
            count++;
        }
    }

    cout << N - (count - D) << endl;
}