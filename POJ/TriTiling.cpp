#include <iostream>
using namespace std;
int dp[31];
void init() {
  dp[0] = 1;
  for(int i=2;i<=30;i+=2){
    dp[i] += dp[i-2]*3;
    for(int j=2;j*2<=i;j++){
      dp[i] += dp[i - j*2] * 2;
    }
  }
}
int main(){
  int n;
  init();
  while(cin >> n){
    if(n==-1)return 0;
    cout << dp[n] << endl;
  }
}
