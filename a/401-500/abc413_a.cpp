#include <iostream>
using namespace std;

int main() {
    int N, M, A;
    cin >> N >> M;

    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> A;
        count += A;
    }

    if (M >= count) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
