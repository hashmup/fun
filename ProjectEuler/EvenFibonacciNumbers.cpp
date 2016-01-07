#include<iostream>

using namespace std;
typedef long long ll;
ll fib[10000];
int main(){
  fib[0] = 1;
  fib[1] = 2;
  int pos = 1;
  while(fib[pos] < 4000000){
    fib[pos+1] = fib[pos] + fib[pos-1];
    pos++;
  }
  ll sum = 0;
  for(int i=0;i<pos;i++)if(fib[i]%2==0)sum+=fib[i];
  cout << sum << endl;
}
