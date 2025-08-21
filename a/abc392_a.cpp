#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int first = A * B;
    int second = B * C;
    int third = A * C;

    if (first == C || second == A || third == B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl; 
    }
    return 0;
}