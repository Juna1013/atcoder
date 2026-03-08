#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (A <= C) {
        if (B <= D) {
            cout << "No" << endl;
            return 0;
        } else {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
