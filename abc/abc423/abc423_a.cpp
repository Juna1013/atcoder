#include <iostream>
using namespace std;

int main() {
    long long X, C;
    cin >> X >> C;

    long long k = X / (1000 + C);
    long long answer = 1000 * k;

    cout << answer << endl;
}
