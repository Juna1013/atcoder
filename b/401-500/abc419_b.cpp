#include <iostream>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    int bag[100];
    int size = 0;

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            bag[size] = x;
            size++;
        } else {
            // 配列から最小値を探す
            int minIndex = 0;
            for (int j = 1; j < size; j++) {
                if (bag[j] < bag[minIndex]) minIndex = j;
            }

            cout << bag[minIndex] << endl;

            // 最小値を削除して配列を詰める
            for (int j = minIndex; j < size - 1; j++) {
                bag[j] = bag[j + 1];
            }
            size--;
        }
    }
}
