#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

vector<int> splitBase(int n){
  vector<int> v;
  v.push_back(n);
  while(n>0){
    int t = n%10;
    v.push_back(t);
    n = (n-t)/10;
  }
  return v;
}

bool isSame(vector<int> v, int num){
    int temp = 1;
    for(size_t i=0;i<v.size();i++)temp*=v[i];
    return (num==temp);
}

vector<int> findSeed(int num){
  set<int> factors;
  set<int>::iterator it;
  vector<int> v;
  for(int i=2;i<=sqrt(num);i++){
    if(num%i==0){
      factors.insert(i);
      factors.insert(num/i);
    }
  }
  for(it=factors.begin();it!=factors.end();it++){
    vector<int> bases = splitBase(*it);
    if(isSame(bases,num))v.push_back(*it);
  }
  return v;
}



int main(){
  vector<int> v = findSeed(1716);
  for(size_t i=0;i<v.size();i++)cout << v[i] << endl;
}
