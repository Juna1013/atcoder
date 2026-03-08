#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int answer = A / B;
    int remainder = A % B;

    if (B / 2 >= remainder) {
        cout << answer << endl;
    } else {
        cout << answer + 1 << endl;
    }
}
