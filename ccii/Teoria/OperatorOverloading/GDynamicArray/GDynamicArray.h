#include <iostream>
using namespace std;

#ifndef G_DYNAMIC_ARRAY_H
#define G_DYNAMIC_ARRAY_H
template <typename T>
class GDynamicArray{
    template <typename U>
    friend ostream& operator<<(ostream& output, const GDynamicArray<U>& arr);
    template<typename U>
    friend istream& operator>>(istream& input, GDynamicArray<U>& arr);
  private:
    int size;
    T *data;
  public:
    GDynamicArray();
    GDynamicArray(int size);
    GDynamicArray(T arr[], int size);
    GDynamicArray(GDynamicArray<T> &o);
    ~GDynamicArray();
    void push_back(T val);
    void insert(int pos, T val);
    void remove(int pos);
    T get(int pos);
    const GDynamicArray<T>& operator=(const GDynamicArray<T>& arr);
    bool operator==(const GDynamicArray<T>& arr) const;
    bool operator!=(const GDynamicArray<T>& arr) const;
    T& operator[](int index);
    T operator[](int index) const;
};

#endif

template <typename T> 
GDynamicArray<T>::GDynamicArray(){
  this -> size = 0;
  data = new T[0];
}

template <typename T>
GDynamicArray<T>::GDynamicArray(int size){
  this->size = size;
  data = new T[size];
}
template <typename T> 
GDynamicArray<T>::~GDynamicArray(){
  delete [] data;
}

template <typename T> 
GDynamicArray<T>::GDynamicArray(T arr[], int size){
  this -> size = size;
  data = new T[size];
  for(int i=0;i<size;i++){
    data[i]=arr[i];
  }
}

template <typename T>
GDynamicArray<T>::GDynamicArray(GDynamicArray<T>& o){
  size = o.size;
  data = new T[size];
  for(int i=0;i<size;i++){
    data[i]=o.data[i];
  }
}

template <typename T>
void GDynamicArray<T>::push_back(T val){
  T *tmp = new T[size+1];
  for(int i=0;i<size;i++){
    tmp[i]=data[i];
  }
  tmp[size] = val;
  delete [] data;
  data = tmp;
  size++;
}

template <typename T>
void GDynamicArray<T>::insert(int pos, T val){
  T *tmp = new T[size+1];
  for(int i=0;i<pos;i++){
    tmp[i]=data[i];
  }
  tmp[pos] = val;
  for(int i=pos;i<size;i++){
    tmp[i+1]=data[i];
  }
  delete [] data;
  data = tmp;
  size++;
}

template <typename T>
void GDynamicArray<T>::remove(int pos){
  T *tmp = new T[size-1];
  for(int i=0;i<pos;i++){
    tmp[i]=data[i];
  }
  for(int i=pos;i<size-1;i++){
    tmp[i]=data[i+1];
  }
  delete [] data;
  data = tmp;
  size--;
}

template <typename T>
T GDynamicArray<T>::get(int pos){
  return data[pos];
}

template <typename T>
T& GDynamicArray<T>::operator[](int index){
  if(index < 0 || index >=size){
    throw out_of_range{"Index out of range"};
  }
  return data[index];
}

template <typename T>
T GDynamicArray<T>::operator[](int index) const{
  if(index < 0 || index >=size){
    throw out_of_range{"Index out of range"};
  }
  return data[index];
}
template <typename T>
const GDynamicArray<T>& GDynamicArray<T>::operator=(const GDynamicArray<T>& arr){
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
bool GDynamicArray<T>::operator==(const GDynamicArray<T>& arr) const{
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
bool GDynamicArray<T>::operator!=(const GDynamicArray<T>& arr) const{
  return !(*this == arr);
}

template <typename T>
ostream& operator<<(ostream& output, const GDynamicArray<T>& arr){
  for(int i=0; i<arr.size; i++){
    output << arr.data[i] << " ";
  }
  output << endl;
  return output;
}
template <typename T>
istream& operator>>(istream& input, GDynamicArray<T>& arr){
  for(int i=0; i < arr.size; i++){
    input >> arr.data[i];
  }
  return input;
}
