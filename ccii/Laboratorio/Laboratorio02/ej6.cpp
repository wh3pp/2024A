#include <iostream>
#include <ctime>
#include  <cstdlib>

using namespace std;

void function(int *&p1, int *&p2, int n){
  p1 = new int[n];
  p2 = new int[n];
  srand(time(NULL));
  for(int i=0;i<n;i++){
    *(p1+i)=rand()%100;
    *(p2+i)=rand()%100;
  }
}
void function2(int *&p1, int *&p2, int n){
  for(int i=0;i<n;i++){
    int tmp = *(p1+i);
    *(p1+i) = *(p2+i);
    *(p2+i) = tmp;
  }
}
void print(int *p, int n){
  for(int i=0; i<n; i++){
    cout << *(p+i) << " ";
  }
  cout << endl;
}
int main(){
  int n=10;
  int *p1,*p2;
  function(p1,p2,n);
  cout << "Antes\n";
  print(p1,n);
  print(p2,n);
  function2(p1,p2,n);
  cout << "Después\n";
  print(p1,n);
  print(p2,n);
}
