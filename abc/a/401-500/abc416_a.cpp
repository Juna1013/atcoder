#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, L, R;
    string S;
    cin >> N >> L >> R >> S;

    for (int i = L - 1; i < R; i++) {
        if (S[i] == 'x') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
