#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  string str1,str2;
  int mul,tmp;
  for(int i=100;i<1000;i++){
    for(int j=100;j<1000;j++){
      mul = i * j;
      str1 = to_string(mul);
      str2 = str1;
      reverse(str2.begin(),str2.end());
      if(str1==str2)tmp = max(tmp,mul);
    }
  }
  cout << tmp << endl;
}
