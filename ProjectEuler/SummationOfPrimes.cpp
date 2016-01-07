#include <iostream>

using namespace std;
typedef long long ll;
const int MAX = 2000001;
bool prime[MAX];
void init(){
  for(int i=0;i<MAX;i++)prime[i] = true;
  prime[0] = prime[1] = false;
  for(int i=2;i<MAX;i++){
    if(prime[i]){
      for(int j=i*2;j<MAX;j+=i)prime[j] = false;
    }
  }
}
int main(){
  init();
  ll sum = 0;
  for(int i=0;i<MAX;i++){
    if(prime[i])sum+=i;
  }
  cout << sum << endl;
}
