#include <iostream>
using namespace std;
void function(double *p1, double *&p2, int tam){
  p2 = new double[tam];
  for(int i=0;i<tam;i++){
    *(p2+i)=*(p1+i);
  }
}

void print(double *arr, int tam){
  for(int i=0;i<tam;i++){
    cout << *(arr+i) << " ";
  }
  cout << endl;
}
int main(){
  double *p1 = new double[6]{1.2,1.3,1.5,6.5,8.32,7.82};
  double *p2;
  function(p1,p2,6);
  cout << "Array 1\n";
  print(p1,6);
  cout << "Array 2\n";
  print(p2,6);
  delete [] p1;
  delete [] p2;
}
