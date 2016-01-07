#include <cmath>
#include <iostream>

using namespace std;
int main(){
  int t;
  double h,w,lo,sh,l;
  cin >> t;
  while(t--){
    cin >> h >> w;
    lo = std::max(h,w);
    sh = std::min(h,w);
    l = sqrt(pow(lo/2.0,2)+pow(sh,2));
    printf("%.12lf\n",l);
  }
}
