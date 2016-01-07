#include <iostream>
using namespace std;

int main(){
  int n,sum=0;
  cin >> n;
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
      if(i*j>n)break;
      sum++;
    }
  }
  cout << sum << endl;
}
