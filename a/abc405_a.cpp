#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, X;
    cin >> R >> X;

    if (X == 1 && 1600 <= R && R <= 2999) {
        cout << "Yes" << endl;
    } else if (X == 2 && 1200 <= R && R <= 2399) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}