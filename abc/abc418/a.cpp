#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    if (S[N - 3] == 't' && S[N - 2] == 'e' && S[N - 1] == 'a') {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
