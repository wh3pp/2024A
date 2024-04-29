#include "GDynamicArray.h"

int main(){
  int arr1[] = {1,2,3,4,5};
  double arr2[] = {1.15,1.45,0.3,39.1}; 
  char arr3[] = {'r','o','n','i'};
  GDynamicArray<int> ent(arr1,5);
  GDynamicArray<double> deci(arr2,4);
  GDynamicArray<char> cad(arr3,4);
  ent.push_back(3);
  deci.push_back(4.14);
  cad.push_back('A');
  ent.print();
  deci.print();
  cad.print();
  GDynamicArray<int> copia(ent);
  copia.print();
  GDynamicArray<char> copia2 = cad;
  copia2.push_back('z');
  copia2.remove(0);
  copia2.push_back('1');
  copia2.push_back('r');
  copia2.insert(6,'i');
  copia2.print();
} 
