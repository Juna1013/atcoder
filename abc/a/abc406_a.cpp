#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (A > C) {
        cout << "Yes" << endl;
        return 0;
    } else if (A == C) {
        if (B > D) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}