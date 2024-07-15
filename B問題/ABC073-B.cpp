#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int A, B;
        cin >> A >> B;
        cnt += B - A + 1;
    }
    cout << cnt << endl;
}
