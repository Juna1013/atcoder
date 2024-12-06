#include <iostream>
using namespace std;

int main() {
    long long H;
    cin >> H;

    long long height = 0; // 植物の累積の高さ
    int day = 0;

    while (height <= H) {
        height += (1LL << day); // height に 2^day を加算
        day++;
    }

    cout << day << endl;

    return 0;
}
