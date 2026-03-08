#include <bits/stdc++.h>
using namespace std;

int main() {
    string D;
    cin >> D;

    if (D[0] == 'N') {
        if (D[1] == 'E') {
            cout << "SW" << endl;
        } else if (D[1] == 'W') {
            cout << "SE" << endl;
        } else {
            cout << 'S' << endl;
        }
    } else if (D[0] == 'S') {
        if (D[1] == 'E') {
            cout << "NW" << endl;
        } else if (D[1] == 'W') {
            cout << "NE" << endl;
        } else {
            cout << 'N' << endl;
        }
    } else if (D[0] == 'W') {
        cout << 'E' << endl;
    } else {
        cout << 'W' << endl;
    }
}
