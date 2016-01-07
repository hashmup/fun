/*
 * 01 napsack problem
 * dp[i][j] := maximum value of the value, when you pick item (from ith to the end) so that the sum of those items is less equal than j.
 */
#include <iostream>

using namespace std;
const int MAX = 3402;

int w[MAX], d[MAX];
int dp[MAX][12880];
int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++)cin >> w[i] >> d[i];
  for(int i=0;i<=m;i++)dp[n][i]=0;
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<=m;j++){
      if(j < w[i])dp[i][j] = dp[i+1][j];
      else dp[i][j] = max(dp[i+1][j], dp[i+1][j - w[i]] + d[i]);
    }
  }
  cout << dp[0][m] << endl;
}
