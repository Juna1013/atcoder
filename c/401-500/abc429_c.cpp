#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[200000];
    int maxA = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] > maxA) maxA = A[i];
    }

    long long freq[200001] = {0};

    for (int i = 0;i < N; i++) {
        freq[A[i]]++;
    }

    long long ans = 0;

    for (int v = 1; v <= maxA; v++) {
        if (freq[v] >= 2) {
            long long cnt2 = (long long)freq[v] * (freq[v] - 1) / 2;
            long long cnt1 = N - freq[v];
            ans += cnt2 * cnt1;
        }
    }

    cout << ans << endl;
}
