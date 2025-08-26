#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    long long n, x, y;
    cin >> n >> x >> y;

    vector<long long> sweet(n);
    vector<long long> salty(n);

    for (int i = 0; i < n; i++) {
        cin >> sweet[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> salty[i];
    }
    
    sort(sweet.rbegin(), sweet.rend());
    sort(salty.rbegin(), salty.rend());

    long long count_sweet = 0;
    long long count_salty = 0;

    for (int i = 0; i < n; i++) {
        count_sweet += sweet[i];
        count_salty += salty[i];

        if (count_sweet > x || count_salty > y) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
}
