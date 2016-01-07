#include <iostream>
using namespace std;
int field[100][100];
int dp[100][100];
int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      cin >> field[i][j];
    }
  }
  dp[0][0] = field[0][0];
  for(int i=0;i<n-1;i++){
    for(int j=0;j<=i;j++){
      dp[i+1][j] = max(dp[i+1][j], dp[i][j] + field[i+1][j]);
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + field[i+1][j+1]);
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++)ans = max(ans, dp[n-1][i]);
  cout << ans << endl;
}
