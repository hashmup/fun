#include <iostream>
#include <cmath>

using namespace std;
bool prime[21];
int dp[21];
void init(){
  for(int i=0;i<21;i++)prime[i] = true;
  prime[1] = false;
  for(int i=2;i<21;i++){
    if(prime[i]){
      for(int j=i*2;j<21;j+=i)prime[j]=false;
    }
  }
}
int main(){
  for(int i=2;i<21;i++){
    int tmp = i;
    for(int j=2;j<21;j++){
      int cnt = 0;
      while(tmp%j==0){
        cnt++;
        tmp/=j;
      }
      dp[j] = max(cnt,dp[j]);
    }
  }
  int ans = 1;
  for(int i=2;i<21;i++)
    ans *= pow(i,dp[i]);
  cout << ans << endl;

}
