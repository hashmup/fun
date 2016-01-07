#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(){
  int n,tmp;
  vector<int> v;
  while(cin >> n){
    if(n==0)break;
    while(true){
      v.clear();
      cin >> tmp;
      if(tmp==0){
        cout << endl;
        break;
      }
      v.push_back(tmp);
      for(int i=0;i<n-1;i++){
        cin >> tmp;
        v.push_back(tmp);
      }
      stack<int> st;
      int pos=0;
      for(int i=1;i<=n;i++){
        st.push(i);
        while(!st.empty()&&st.top()==v[pos]){
          st.pop();
          pos++;
        }
      }
      if(pos==n)cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}
