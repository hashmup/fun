#include <iostream>
using namespace std;
const int MAX = 150000;
int strength[MAX];
int dp[2][MAX];
int main(){
  int p;
  cin >> p;
  for(int i=0;i<p;i++)cin >> strength[i];
  dp[0][0] = strength[0];
  dp[1][0] = 0;
  for(int i=1;i<p;i++){
    dp[0][i] = max(dp[0][i-1], dp[1][i-1] + strength[i]);
    dp[1][i] = max(dp[1][i-1], dp[0][i-1] - strength[i]);
  }
  cout << dp[0][p-1] << endl;
}
