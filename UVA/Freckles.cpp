#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
const double INF = 999999.0;
typedef pair<double,double> PD;

double dist[100][100];
double dp[100];
bool used[100];
double distance(PD v1, PD v2){
  return sqrt(pow(v1.first-v2.first,2)+pow(v1.second-v2.second,2));
}

int main(){
  int num,n;
  double x,y;
  vector<PD> v;
  cin >> num;
  for(int k=0;k<num;k++){
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> x >> y;
      v.push_back(PD(x,y));
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        double d = distance(v[i],v[j]);
        dist[i][j] = dist[j][i] = d;
      }
    }
    fill(dp,dp+n,INF);
    fill(used,used+n,false);
    dp[0] = 0;
    double cost = 0;
    while(true){
      int v = -1;
      for(int i=0;i<n;i++){
        if(!used[i] && (v==-1 || dp[i] < dp[v]))v = i;
      }
      if(v==-1)break;
      used[v] = true;
      cost += dp[v];
      for(int i=0;i<n;i++){
        dp[i] = min(dp[i],dist[v][i]);
      }
    }
    printf("%.2lf\n",cost);
  }
}
