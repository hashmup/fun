#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;
const long INF = 1000000000;
vector<vector<long> > dp;
void init(int n){
  for(int i=0;i<n+1;i++){
    vector<long> v;
    dp.push_back(v);
    for(int j=0;j<n+1;j++)
      dp[i].push_back(-INF);
  }
}
int main(){
  int n,tmp;
  cin >> n;
  init(n);
  vector<long> a;
  vector<long> b;
  for(int i=0;i<n;i++){
    cin >> tmp;
    a.push_back(tmp);
  }
  for(int i=0;i<n;i++){
    cin >> tmp;
    b.push_back(tmp);
  }
  if(n==1){
    long ans = max(a[0],b[0]);
    ans = (ans>0) ? ans : 0;
    cout << ans << endl;
  } else {
    dp[0][0] = b[0];
    dp[0][1] = (a[0] >= 0) ? a[0] : -INF;
    for(int i=1;i<n;i++){
      dp[i][0] = dp[i-1][0]+b[0];
      for(int j=1;j<=i+1;j++){
        if(dp[i-1][j]>=0)dp[i][j] = dp[i-1][j] + b[j];
        else dp[i][j] = -INF;
        if(dp[i-1][j-1] + a[j-1]>=0)dp[i][j] = max(dp[i][j],dp[i-1][j-1] + a[j-1]);
      }
    }
    if(dp[n-2][n-1]>=0)dp[n-1][n] = dp[n-2][n-1] + a[n-1];
    else dp[n-1][n] = -INF;
    long ans = 0;
    for(int i=0;i<=n;i++){
      ans = max(ans,dp[n-1][i]);
    }
    cout << ans << endl;
  }
}
