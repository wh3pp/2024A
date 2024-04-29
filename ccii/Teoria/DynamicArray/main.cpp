#include "dynamicArray.h"

int main(){
  int arr[] = {1,2,3,4,5,6,7};
  DynamicArray a(arr,7);
  a.push_back(8);
  a.push_back(10);
  a.push_back(20);
  a.push_back(19);
  a.insert(1,22);
  a.print();
  a.remove(1);
  a.push_back(0);
  a.print();
  a.remove(2);
  a.remove(3);
  a.print();
  a.push_back(2);
  a.print();
  a.push_back(88);
  a.push_back(69);
  a.print();
  a.remove(2);
  a.insert(2,4);
  a.print();
}
