#include <iostream>
using namespace std;
void function(double *&arr){
  int tam;
  cout << "Tamaño del array: ";
  cin >> tam;
  arr = new double[tam];
  for(int i=0;i<tam;i++){
    cout << "Ingrese: ";
    cin >> *(arr+i);
  }
  for(int i=0; i<tam; i++){
    cout << *(arr+i) << " ";
  }
  cout << endl;
}
int main(){
  double *arr;
  function(arr);
  delete [] arr;
}
