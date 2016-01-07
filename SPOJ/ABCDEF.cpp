#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
  unordered_map<int,int> map1,map2;
  unordered_map<int,int>::iterator it,val;
  vector<int> v;
  int n,tmp,sum=0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> tmp;
    v.push_back(tmp);
  }
  // make a hashtable for a*b + c O(n^3)
  for(size_t i=0;i<v.size();i++){
    for(size_t j=0;j<v.size();j++){
      for(size_t k=0;k<v.size();k++){
        map1[v[i]*v[j]+v[k]]++;
      }
    }
  }
  // make a hashtable for d(e + f) O(n^3)
  for(size_t i=0;i<v.size();i++){
    for(size_t j=0;j<v.size();j++){
      for(size_t k=0;k<v.size();k++){
        if(v[i]!=0){
          map2[v[i]*(v[j]+v[k])]++;
        }
      }
    }
  }

  // iterate map2 and find value from map1 => binary_search O(logn) for O(n^3) times
  for(it = map2.begin();it!=map2.end();it++){
    val = map1.find(it->first);
    if(val!=map1.end())sum += val->second*it->second;
  }
  cout << sum << endl;
}
