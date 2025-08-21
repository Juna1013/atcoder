#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int T[N], V[N];
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> V[i];
    }

    int time = 0;
    int water = 0;

    for (int i = 0; i < N; i++) {
        int diff = T[i] - time;
        water -= diff;

        if (water < 0) {
            water = 0;
        }

        water += V[i];
        time = T[i];
    }

    cout << water << endl;

}
