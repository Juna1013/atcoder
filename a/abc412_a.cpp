#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N;

    int count = 0;
    for (int i= 0; i < N; i++) {
        cin >> A >> B;
        if (A < B) count++;
    }
    
    cout << count << endl;
}
