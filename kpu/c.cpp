#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<vector<int> > vvi;
  int t,n,tmp;
  cin >> t;
  for(int i=0;i<t;i++){
    cin >> n;
    vvi.clear();
    for(int j=0;j<n;j++){
      vector<int> vi;
      for(int k=0;k<n;k++){
        cin >> tmp;
        vi.push_back(tmp);
      }
      vvi.push_back(vi);
    }
    bool flag = false;
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
          if(j!=k&&j!=l&&k!=l){
            if(vvi[j][k]!=-1&&vvi[k][l]!=-1&&vvi[j][l]!=-1&&vvi[j][k]+vvi[k][l]<vvi[j][l])flag = true;
            if(vvi[j][l]==-1&&vvi[j][k]!=-1&&vvi[k][l]!=-1)flag = true;
          }
          if(flag)break;
        }
        if(flag)break;
      }
      if(flag)break;
    }
    for(int j=0;j<n;j++){
      if(vvi[j][j]!=0)flag = true;
    }
    if(flag)cout << "NO" << endl;
    else cout << "YES" << endl;
  }
}
