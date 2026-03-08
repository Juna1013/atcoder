#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, A, B;
    string S;
    cin >> N >> A >> B >> S;

    for (int i = A; i < N - B; i++) {
        cout << S[i];
    }
    cout << endl;
}
