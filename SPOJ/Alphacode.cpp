#include <iostream>

using namespace std;
const int MAX = 5100;
long dp[MAX];
void init(){
  for(int i=0;i<MAX;i++)dp[i]=0;
}
int main(){
  string str;
  long last,num,tmp;
  while(cin >> str){
    if(str=="0")break;
    init();
    dp[0]=1;
    last = str[0]-'0';
    num = 0; // number of decodings with last 2 compose 1 digit i.e. 10,11,...26
    for(size_t i=1;i<str.size();i++){
      if(last==0){
        if(str[i]=='0')break;
        dp[i]=dp[i-1];
        num = 0; // <= forgot about this, takes pretty much time
      } else if(last*10+str[i]-'0'<=26){
        tmp = num;
        num = dp[i-1] - tmp;
        if(str[i]=='0'){
          dp[i] = num;
        } else {
          dp[i] = tmp + num*2;
        }
      } else {
        dp[i] = dp[i-1];
        num = 0;
      }
      last = str[i]-'0';
    }
    cout << dp[str.size()-1] << endl;
  }
}
