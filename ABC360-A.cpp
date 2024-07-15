#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  if (s == "RSM" || s == "RMS" || s == "SRM") {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
