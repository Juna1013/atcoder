// うまく動作していない
#include <bits/stdc++.h>
using namespace std;

int main() {
    int A[5];
    int Z[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }

    bool initial_match = true;
    for (int i = 0; i < 5; i++) {
        if (A[i] != Z[i]) {
            initial_match = false;
            break;
        }
    }
    if (initial_match) {
        cout << "Yes" << endl;
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        int B[5];
        for (int j = 0; j < 5; j++) {
            B[j] = A[j];
        }

        int temp = B[i];
        B[i] = B[i + 1];

        bool match = true;
        for (int j = 0; j < 5; j++) {
            if (B[j] != Z[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            cout << "Yes" << endl;
            return 0; 
        }
    }
    cout << "No" << endl;
}
