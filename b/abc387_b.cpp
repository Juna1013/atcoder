#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    int found = 0;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i * j == x) {
                found += x;
                break;
            }
        }
    }

    cout << 45 * 45 - found << endl;

}