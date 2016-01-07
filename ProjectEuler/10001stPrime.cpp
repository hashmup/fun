#include <iostream>

using namespace std;

typedef long long ll;
const ll MAX = 100000000;
bool prime[MAX];
void init(){
  for(ll i=0;i<MAX;i++)prime[i] = true;
  prime[0] = false;
  prime[1] = false;
  for(ll i=0;i<MAX;i++){
    if(prime[i]){
      for(ll j=i*2;j<MAX;j+=i)prime[j] = false;
    }
  }
}

int main(){
  init();
  int cnt = 0;
  for(ll i=0;i<MAX;i++){
    if(prime[i])cnt++;
    if(cnt==10001){
      cout << i << endl;
      break;
    }
  }
}
