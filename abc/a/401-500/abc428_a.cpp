#include <iostream>
using namespace std;

int main() {
    int S, A, B, X;
    cin >> S >> A >> B >> X;

    int time = 0;
    int distance = 0;
    
    while (time < X) {
        // 走る
        int runtime;
        if (A <= X - time) {
            runtime = A;
        } else {
            runtime = X - time;
        }

        distance += S * runtime;
        time += runtime;

        // 残り時間の管理
        if (time >= X) {
            break;
        }
        
        // 休む
        int resttime;
        if (B <= X - time) {
            resttime = B;
        } else {
            resttime = X - time;
        }

        time += resttime;
    }
    cout << distance << endl;
}
