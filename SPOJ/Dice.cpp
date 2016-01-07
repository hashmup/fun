/*
What I've learned from this
pow(6,i) doesn't fit in int, long long..., so you have to think about the boundary of n which makes all possibility to 0.
First run test cases to get the bound, then set it as MAX.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX = 740;
double dp[MAX][MAX*6+1];
// void solve(int n, int m){
//   for(int i=1;i<=6;i++)dp[0][i]=1;
//   for(int i=1;i<n;i++){
//     ll maxV = 0;
//     for(int j=1;j<=6*MAX;j++)dp[i&1][j]=0;
//     for(int j=i;j<=6*i;j++){
//       for(int k=1;k<=6;k++){
//         dp[i&1][j+k] += dp[(i-1)&1][j];
//         maxV = max(maxV,dp[i&1][j+k]);
//       }
//     }
//     if(maxV*100/pow(6,i)==0){
//       cout << 0 << endl;
//       return;
//     }
//   }
//   int ratio = floor((double)dp[(n-1)&1][m]*100.0/pow(6,n));
//
//   cout << ratio << endl;
// }

void init(){
  for(int i=1;i<=6;i++)dp[0][i]=100.0/6;
  for(int i=1;i<MAX;i++){
    for(int j=i;j<=6*i;j++){
      for(int k=1;k<=6;k++){
        dp[i][j+k] += dp[i-1][j]/6.0;
      }
    }
  }
}

int main(){
  int t,n,k;
  cin >> t;
  init();
  for(int i=0;i<t;i++){
    cin >> n >> k;
    if(n>=MAX||n>k||(n*6)<k)cout << 0 << endl;
    else {
      int ratio = floor(dp[n-1][k]);
      cout << ratio << endl;
    }
  }
}
