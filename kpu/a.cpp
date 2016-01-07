#include<iostream>
#include <algorithm>

using namespace std;

int countNum(string str){
  reverse(str.begin(),str.end());
  string tokyo = "oykot";
  string kyoto = "otoyk";
  size_t pos = 0;
  int cnt = 0;
  while(true){
    size_t t1,t2;
    t1 = str.find(tokyo,pos);
    t2 = str.find(kyoto,pos);
    if(t1==string::npos&&t2==string::npos)break;
    cnt++;
    pos = min(t1,t2)+5;
  }
  return cnt;
}

int main(){
  int n;
  string str;
  cin >> n;
  while(n--){
    cin >> str;
    cout << countNum(str) << endl;
  }
}
