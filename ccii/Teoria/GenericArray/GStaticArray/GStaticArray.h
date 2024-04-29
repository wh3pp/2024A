#include <iostream>
using namespace std;

#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

template <typename T>
class GStaticArray {
    int size;
    T *data;
  public:
    GStaticArray(int size);
    GStaticArray(GStaticArray<T> &a);
    ~GStaticArray();
    T get(int index) const;
    void set (int index, T value);
    int getsize() const;
    void print() const;
};

#endif

template <typename T>
GStaticArray<T>::GStaticArray(int size){
  this -> size = size;
  data = new T[size];
}

template <typename T>
GStaticArray<T>::GStaticArray(GStaticArray<T> &a){
  size = a.size;
  data = new T[size];
  for (int i=0; i<size; i++){
    data[i] = a.data[i];
  }
}

template <typename T>
GStaticArray<T>::~GStaticArray(){
  delete [] data;
}

template <typename T>
T GStaticArray<T>::get(int index) const{
  return data[index];
}

template <typename T>
void GStaticArray<T>::set(int index, T value){
  data[index] = value;
}

template <typename T>
int GStaticArray<T>::getsize() const{
  return size;
}

template <typename T>
void GStaticArray<T>::print() const{
  for (int i=0; i<size; i++){
    cout << data[i] << ", ";
  }
  cout << endl;
}
