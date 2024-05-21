#include <iostream>
using namespace std;

template <typename T>
void ordenar(T *array, int tam, bool ascendente){
  if(!ascendente){
    for(int i=0; i<tam ; i++){
      for(int j=0; j<tam; j++){
        if(array[i] > array[j]){
          T tmp;
          tmp = array[i];
          array[i] = array[j];
          array[j] = tmp;
        }
      }
    }
  }
  else{
    for(int i=0; i<tam ; i++){
      for(int j=0; j<tam; j++){
        if(array[i] < array[j]){
          T tmp;
          tmp = array[i];
          array[i] = array[j];
          array[j] = tmp;
        }
      }
    }
  }
}

template <typename T>
void print(T *array, int tam){
  for(int i=0; i<tam; i++){
    cout << array[i] << ", ";
  }
  cout << endl;
}

int main(){
  int ints[] = {10,2,5,4,5};
  char chars[] = {'a','z','Z','d','A'};
  float floats[] = {2.1,2.4,1.0,0.2,0.3};
  double doubles[] = {1.2314,3.23123,132.2132,0.00001,231.321};
  long longs[] = {21321412421,41244301003201,10000024000,1203030020102,934108518982413};
  cout << "\tOrdenamiento ascendente\n";
  ordenar(ints,5,true);
  print(ints,5);
  ordenar(chars,5,true);
  print(chars,5);
  ordenar(floats,5,true);
  print(floats,5);
  ordenar(doubles,5,true);
  print(floats,5);
  ordenar(longs,5,true);
  print(longs,5);
  cout << "\tOrdenamiento Descendiente\n";
  ordenar(ints,5,false);
  print(ints,5);
  ordenar(chars,5,false);
  print(chars,5);
  ordenar(floats,5,false);
  print(floats,5);
  ordenar(doubles,5,false);
  print(doubles,5);
  ordenar(longs,5,false);
  print(longs,5);
  
}
