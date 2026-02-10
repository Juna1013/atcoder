#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    int counter = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i % 2 == 0) {
            counter += A[i];
        }
    }
    cout << counter << endl;
}
