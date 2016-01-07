#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
  int n,tmp,cnt;
  ll sum;
  vector<ll> v;
  vector<int> v2;
  while(cin >> n){
    if(n==0)break;
    for(int i=0;i<n;i++){
      for(int j=0;j<5;j++){
        cin >> tmp;
        v2.push_back(tmp);
      }
      sort(v2.begin(),v2.end());
      sum = 0;
      for(int j=0;j<5;j++)sum += pow(1000,j)*v2[i];
      v.push_back(sum);
    }
    cnt = 0;
    tmp = 0;
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++){
      if(v[i-1]==v[i])tmp++;
      else {
        cnt = max(tmp,cnt);
        tmp = 0;
      }
    }
    cout << cnt << endl;
  }
}
