#include <iostream>
using namespace std;
#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

template <typename T>
class GStaticArray {
    template <typename U>
    friend ostream& operator<<(ostream& output, const GStaticArray<U>& arr);
    template <typename U>
    friend istream& operator>>(istream& input, GStaticArray<U>& arr);
  private:
    int size;
    T *data;
  public:
    GStaticArray(int size);
    GStaticArray(GStaticArray<T> &a);
    ~GStaticArray();
    T get(int index) const;
    void set (int index, T value);
    int getsize() const;
    const GStaticArray<T>& operator=(const GStaticArray<T>& arr);
    bool operator==(const GStaticArray<T>& arr) const;
    bool operator!=(const GStaticArray<T>& arr) const;
    T& operator[](int index);
    T operator[](int index) const;
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
T& GStaticArray<T>::operator[](int index){
  if(index < 0 || index >=size){
    throw out_of_range{"Index out of range"};
  }
  return data[index];
}

template <typename T>
T GStaticArray<T>::operator[](int index) const{
  if(index < 0 || index >=size){
    throw out_of_range{"Index out of range"};
  }
  return data[index];
}
template <typename T>
const GStaticArray<T>& GStaticArray<T>::operator=(const GStaticArray<T>& arr){
  if(&arr != this){
    if(size != arr.size){
      delete [] data;
      size = arr.size;
      data = new T[size];
    }

    for(int i=0; i<size; i++){
      data[i] = arr.data[i];
    }
  }
  return *this;
}

template <typename T>
bool GStaticArray<T>::operator==(const GStaticArray<T>& arr) const{
  if(size != arr.size){
    return false;
  }
  for(int i=0; i<size; i++){
    if(data[i] != arr.data[i]){
      return false;
    }
  }
  return true;
}

template <typename T>
bool GStaticArray<T>::operator!=(const GStaticArray<T>& arr) const{
  return !(*this == arr);
}

template <typename T>
ostream& operator<<(ostream& output, const GStaticArray<T>& arr){
  for(int i=0; i<arr.size; i++){
    output << arr.data[i] << " ";
  }
  output << endl;
  return output;
}
template <typename T>
istream& operator>>(istream& input, GStaticArray<T>& arr){
  for(int i=0; i < arr.size; i++){
    input >> arr.data[i];
  }
  return input;
}
