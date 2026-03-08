#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i > 0 && A[i] <= A[i - 1]) {
            cout << "No" << endl; 
            return 0;
        }
    }
    cout << "Yes" << endl;
}
