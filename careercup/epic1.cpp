#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<string> genCharSequence(int d){
  vector<string> table;
  table.push_back("");;
  table.push_back("vtfrq");
  table.push_back("ftk");
  table.push_back("wzbg");
  table.push_back("rs");
  table.push_back("");
  table.push_back("fir");
  table.push_back("p");
  table.push_back("lo");
  table.push_back("p");
  set<string> s;
  set<string>::iterator it;
  vector<string> v;
  v.push_back("");
  while(d>0){
    int curr_d = d%10;
    for(size_t j=0;j<table[curr_d].size();j++){
      for(size_t i=0;i<v.size();i++){
        s.insert(table[curr_d][j]+v[i]);
      }
    }
    if(table[curr_d].size()==0){
      for(size_t i=0;i<v.size();i++)s.insert(v[i]);
    }
    v.clear();
    for(it = s.begin();it!=s.end();it++){
      v.push_back(*it);
    }
    s.clear();
    d = (d-curr_d)/10;
  }
  return v;
}

int main(){
  vector<string> v = genCharSequence(9801);
  for(size_t i=0;i<v.size();i++){
    cout << v[i] << endl;
  }
}
