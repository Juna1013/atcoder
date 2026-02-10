#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int A[100];
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    for (int i = 0; i < N; i++) {
        if (sum - A[i] == M) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
