#include <iostream>
#include <cmath>
using namespace std;

int main(){
  for(int i=1;i<1000;i++){
    for(int j=i+1;j<1000;j++){
      if(sqrt(i*i+j*j)+i+j==1000){
        cout << i << " " << j << " " << sqrt(i*i+j*j) << endl;
        cout << (i*j*sqrt(i*i+j*j)) << endl;
      }
    }
  }
}
