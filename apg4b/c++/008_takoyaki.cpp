#include <bits/stdc++.h>
using namespace std;

int main() {
  int p;
  cin >> p;

  if (p == 1) {
    int price, N;
    cin >> price >> N;
    cout << price * N << endl;
  }

  if (p == 2) {
    string text;
    int price, N;
    cin >> text >> price >> N;
    cout << text << "!" << endl;
    cout << price * N << endl;
  }

}
