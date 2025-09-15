#include <iostream>
using namespace std;

int main(){
    // n：ドアの数、r：開始する部屋、a[]：ドアの状態
    int n, r, a[200005], cnt, sum;
	cin >> n >> r;

	// 入力処理
    for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i]) sum++; // a[i]==1なら閉まっているから sum++
	}

	// 左端から連続して「閉まっているドア」を数える
    // ただし開始位置の右側のドア (r+1 番) はスキップ
    for(int i = 1; i <= n; i++){
		if(a[i] && i != r + 1) cnt++;
		else break;
	}

	// 右端からも同様に連続して「閉まっているドア」を数える
    // ただし開始位置の左側のドア (r 番) はスキップ
    for(int i = n; i >= 1; i--){
		if(a[i] && i != r) cnt++;
		else break;
	}

	// 場合分け
    if(sum == n) {
        // 全部しまっている → 何もする必要がない
        cout << 0 << "\n";
    } else if(sum == 0) {
        // 全部開いている → 全部閉めるだけなのでn回
        cout << n << "\n";
    } else {
        cout << n - cnt - cnt + sum << "\n";
    }
}