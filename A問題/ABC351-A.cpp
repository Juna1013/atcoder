#include <iostream>
using namespace std;

int main()
{
  int a1, a2, a3, a4, a5, a6, a7, a8, a9;
  int b1, b2, b3, b4, b5, b6, b7, b8;
  int c;
  
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9;
  cin >> b1 >> b2 >> b3 >> b4 >> b5 >> b6 >> b7 >> b8;
  
  c = (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9) - (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8) + 1;
  cout << c << endl;
}
