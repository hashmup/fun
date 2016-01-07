#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  vector<long> v;
  long x;
  int n=0;
  while(cin >> x){
    n++;
    v.push_back(x);
    sort(v.begin(),v.end());
    if(n%2==1){
      cout << v[(n-1)/2] << endl;
    } else {
      long median = (long)floor((v[n/2-1]+v[n/2])/2);
      cout << median << endl;
    }
  }
}

