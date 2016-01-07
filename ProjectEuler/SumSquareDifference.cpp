#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
int main(){
  ll sum = 0;
  ll square = 0;
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    sum += i*i;
    square += i;
  }
  cout << (square*square - sum) << endl;
}
