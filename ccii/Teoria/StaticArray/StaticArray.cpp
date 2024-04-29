#include "StaticArray.h"
#include <iostream>
using namespace std;

StaticArray::StaticArray(int size){
  this -> size = size;
  data = new int[size];
  for (int i=0; i<size; i++){
    data[i] = 0;
  }
}

StaticArray::~StaticArray(){
  delete [] data;
}

StaticArray::StaticArray(StaticArray &a){
  size = a.size;
  data = new int[size];
  for (int i=0; i<size; i++){
    data[i] = a.data[i];
  }
}

int StaticArray::get(int index) const{
  return data[index];
}

void StaticArray::set(int index, int value){
  data[index] = value;
}

int StaticArray::getsize() const{
  return size;
}

void StaticArray::print() const{
  for (int i=0; i<size; i++){
    cout << data[i] << " ";
  }
  cout << endl;
}
