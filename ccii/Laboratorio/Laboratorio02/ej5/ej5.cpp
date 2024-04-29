#include <iostream>
using namespace std;
void function(int *&p, int n){
  p = new int[n];
  for(int i=0;i<n;i++){
    *(p+i) = 0;
  }
}
int main(){
  int n=8;
  int *p=NULL;
  function(p,n);
  for(int i=0;i<n;i++){
    cout << *(p+i) << " ";
  }
  cout << endl;
}
