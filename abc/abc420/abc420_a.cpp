#include <iostream>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    int answer = X + Y;
    if (answer > 12) {
        cout << answer - 12 << endl;
    } else {
        cout << answer << endl;
    }
}
