#include <bits/stdc++.h>
using namespace std;

int main() {
    double x;
    cin >> x;

    if (x < 37.5) {
        cout << 3 << endl;
    } else if (x < 38) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
}