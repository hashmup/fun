#include<iostream>

using namespace std;
bool a[1000];
int main(){
  for(int i=0;i<1000;i++)a[i]=false;
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    if((i)%3==0||(i)%5==0)a[i]=true;
  }
  int sum = 0;
  for(int i=0;i<n;i++){
    if(a[i])sum+=i;
  }
  cout << sum << endl;
}
