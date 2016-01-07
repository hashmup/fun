#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
const int MAX_V = 1000;
const int INF = 9999999;
struct edge{int to,cost};
typedef pair<int, int> P;
int cost[MAX_V][MAX_V];
vector<edge> G[MAX_V];
int d[MAX_V];

bool isDiffOne(string s1, string s2){
  if(s1.size()!=s2.size())return false;
  int cnt = 0;
  for(int i=0;i<s1.size();i++){
    if(s1[i]!=s2[i])cnt++;
  }
  return (cnt==1);
}

void makeCostTable(vector<string> dict){
  for(int i=0;i<dict.size();i++){
    for(int j=i+1;j<dict.size();j++){
      if(isDiffOne(dict[i],dict[j])){
        G[i].push_back(edge(j,1));
      } else {
        G[i].push_back(edge(j,INF));
      }
    }
  }
}

void dijkstra(int s,int n){
  priority_queue<P,vector<P>, greater<P> > que;
  fill(d,d+n,INF);
  d[s] = 0;
  que.push(P(0,s));
  while(!que.empty()){
    P p = que.top();que.pop();
    int v = p.second;
    if(d[v] < p.first)continue;
    for(int i=0;i<G[v].size();i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to],e.to));
      }
    }
  }
}

int main(){
  int n;
  string str;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> str;
    dict.push_back(str);
  }
}
