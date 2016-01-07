#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int h,v;
  double height;
  cin >> h >> v;
  height = h / sin(v * M_PI / 180.0);
  cout << ceil(height) << endl;
}
