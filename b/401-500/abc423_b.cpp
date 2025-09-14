#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int L[105];
    int A[105];
    int B[105];

    for (int i = 1; i <= N; i++) {
        cin >> L[i];
    }

    for (int i = 0; i <= N; i++) {
        A[i] = 0;
        B[i] = 0;
    }

    A[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (L[i] == 0 && A[i-1] == 1) {
            A[i] = 1;
        } else {
            break;
        }
    }

    B[N] = 1;
    for (int i = N; i >= 1; i--) {
        if (L[i] == 0 && B[i] == 1) {
            B[i-1] = 1;
        } else {
            break;
        }
    }

    int count = 0;
    for (int i = 0; i <= N; i++) {
        if (A[i] == 0 && B[i] == 0) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
