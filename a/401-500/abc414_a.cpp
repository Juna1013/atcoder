#include <iostream>
using namespace std;

int main() {
    int N, L, R, X, Y;
    cin >> N >> L >> R;

    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        if (L >= X && R <= Y) {
            count++;
        }
    }
    cout << count << endl;
}
