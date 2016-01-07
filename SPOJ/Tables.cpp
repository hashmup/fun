#include<iostream>
#include<queue>
using namespace std;
int main(){
  priority_queue<int> que;
  int n,k,s,sum,tmp,cnt=0;
  cin >> n >> k >> s;
  for(int i=0;i<n;i++){
    cin >> tmp;
    que.push(tmp);
  }
  sum = k*s;
  while(sum>0){
    sum-=que.top();que.pop();
    cnt++;
  }
  cout << cnt << endl;
}
