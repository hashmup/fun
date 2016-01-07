/*
What I've learned from this
LCS(Longest Common Subsequence)
Suppose we have 2 strings s and t, compute the length of the common Subsequence which is Si1Si2....Sim (i1<i2<...<im)
dp[i][j] = length of the LCS between s1...si and t1...tj
if s[i] == t[j] then dp[i+1][j+1] = dp[i][j]+1
otherwise dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 6100;
int dp[MAX+1][MAX+1];
void init(int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      dp[i][j]=0;
    }
  }
}
int main(){
  int t;
  string str,rev_str;
  cin >> t;
  for(int i=0;i<t;i++){
    cin >> str;
    rev_str = str;
    reverse(rev_str.begin(),rev_str.end());
    init(str.size()+1);
    for(size_t j=0;j<str.size();j++){
      for(size_t k=0;k<str.size();k++){
        if(str[j]==rev_str[k]){
          dp[j+1][k+1] = dp[j][k] + 1;
        } else {
          dp[j+1][k+1] = max(dp[j][k+1], dp[j+1][k]);
        }
      }
    }
    int len = str.size()-dp[str.size()][str.size()];
    cout << len << endl;
  }
}
