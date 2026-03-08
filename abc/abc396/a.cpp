#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int count = 0;
    for (int i = 2; i < N; i++) {
        if (A[i - 2] == A[i - 1] && A[i - 1] == A[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}