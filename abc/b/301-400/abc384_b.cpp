#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, R, D, A;
    cin >> N >> R;

    for (int i = 0; i < N; i++) {
        cin >> D >> A;
        if (D == 1) {
            if (1600 <= R && R <= 2799) {
                R += A;
            }
        } else {
            if (1200 <= R && R <= 2399) {
                R += A;
            }
        }
    }

    cout << R << endl;
}
