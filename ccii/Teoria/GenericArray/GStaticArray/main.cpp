#include "GStaticArray.h"
int main(){
  GStaticArray<int> a(5);
  GStaticArray<char> b(5);
  GStaticArray<double> c(5);
  a.set(0,1);
  a.set(1,2);
  b.set(0,'a');
  b.set(2,'c');
  c.set(0,3.14);
  c.set(4,5.1213);
  cout << a.get(0) << endl;
  a.print();
  cout << b.get(0) << endl;
  b.print();
  cout << c.get(0) << endl;
  c.print();
  GStaticArray<char> d = b;
  cout << b.get(0) << endl;
  d.print();
}
