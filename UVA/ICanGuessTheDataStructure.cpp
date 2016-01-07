#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main(){
  int n,tmp,command,cnt;
  int isStack,isQueue,isPQueue;
  stack<long> st;
  queue<long> que;
  priority_queue<long> pque;
  while(cin >> n){
    isStack = isQueue = isPQueue = 0;
    while(!st.empty())st.pop();
    while(!que.empty())que.pop();
    while(!pque.empty())pque.pop();
    for(int i=0;i<n;i++){
      cin >> command >> tmp;
      if(command==1){
        st.push(tmp);que.push(tmp);pque.push(tmp);
        isStack+=1;
        isQueue+=1;
        isPQueue+=1;
      } else {
        if(!st.empty()&&st.top()==tmp){
          isStack+=1;
          st.pop();
        }
        if(!que.empty()&&que.front()==tmp){
          isQueue+=1;
          que.pop();
        }
        if(!pque.empty()&&pque.top()==tmp){
          isPQueue+=1;
          pque.pop();
        }
      }
    }
    if(isStack!=n&&isQueue!=n&&isPQueue!=n){
      cout << "impossible" << endl;
    } else if((isStack==n&&isQueue==n)||(isStack==n&&isPQueue==n)||(isQueue==n&&isPQueue==n)){
      cout << "not sure" << endl;
    } else if(isStack==n){
      cout << "stack" << endl;
    } else if(isQueue==n) {
      cout << "queue" << endl;
    } else {
      cout << "priority queue" << endl;
    }
  }
}
