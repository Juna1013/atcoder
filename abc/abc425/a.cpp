#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int answer = 0;
        if (i % 2 == 0) {
            answer = -1 * (i + 1) * (i + 1) * (i + 1);
        } else {
            answer = (i + 1) * (i + 1) * (i + 1);
        }
        cnt += answer;
    }
    cout << cnt << endl;
}
