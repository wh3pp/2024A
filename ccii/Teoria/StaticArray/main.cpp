#include "StaticArray.h"
#include <iostream>
using namespace std;

int main(){
  StaticArray a(2);
  cout << a.get(0) << endl;
  a.set(1,100);
  cout << a.get(1) << endl;
  a.print();
  if (true){
    StaticArray b=a;
    b.print();
  }
  cout << a.get(1) << endl;
  a.print();
}
