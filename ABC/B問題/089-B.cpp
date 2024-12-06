#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  string answer = "Three";
  
  for (int i = 0; i < N; i++) {
    string a;
    cin >> a;
    if (a == "Y") {
      answer = "Four";
    }
  }
  cout << answer << endl;
}
