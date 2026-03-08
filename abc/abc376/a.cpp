#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c, t, memory, count;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
    cin >> t;
    if (i == 0) {
        count++;
    } else if (memory - t > c) {
        count++;
    } else {
        break;
    }
    memory = t;
    }

    cout << count << endl;
}