#include <iostream>
#include "GDynamicArray.h"
using namespace std;

int main(){
  int arr1[] = {1,2,3,4,5};
  GDynamicArray<int> ent(5);
  GDynamicArray<int> num(arr1,5);
  cin >> ent;
  cout <<"num: " << ent;
  cout <<"ent: " << num;
  num = ent;
  cout << "num(num=ent): "<< num;
  bool a = (ent == num);
  cout << "ent == num: "<< a << endl;
  cout << "num[1]: " << num[1] << endl;
  num[1] = 102;
  cout << "num[1](num[1]=102): " << num[1] <<endl;
} 
