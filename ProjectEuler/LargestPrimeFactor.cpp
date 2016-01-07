#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MAX = 1000000000000;

bool prime[MAX];
void init(ll n){
  for(ll i=0;i<=sqrt(n);i++)prime[i] = true;
  prime[0] = false;
  prime[1] = false;
  for(ll i=0;i<=sqrt(n);i++){
    if(prime[i]){
      for(ll j=2*i;j<=sqrt(n);j+=i)prime[j]=false;
    }
  }
}
int main(){
  ll n = 600851475143;
  init(n);
  ll tmp = n;
  for(int i=2;i<n;i++){
    if(tmp%i==0){
      cout << i << endl;
      tmp /= i;
    }
    if(tmp < i)break;
  }
}
