#include <iostream>

using namespace std;
int s[10],e[10];
void init(){
  for(int i=0;i<10;i++)s[i] = e[i] = 0;
}
int main(){
  int n,tot;
  while(cin >> n){
    if(n==-1)break;
    for(int i=0;i<n;i++)cin >> s[i] >> e[i];
    tot = s[0] * e[0];

    for(int i=1;i<n;i++){
      tot += s[i] * (e[i]-e[i-1]);
    }
    cout << tot << " miles" << endl;
  }
}
