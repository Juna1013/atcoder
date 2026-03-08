#include <iostream>
using namespace std;

int main() {
    int N, A[100], X;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> X;

    for (int i = 0; i < N; i++) {
        if (A[i] == X) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
