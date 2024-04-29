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
  std::cout << a.get(0) << std::endl;
  a.print();
  std::cout << b.get(0) << std::endl;
  b.print();
  std::cout << c.get(0) << std::endl;
  c.print();
  GStaticArray<char> d = b;
  std::cout << b.get(0) << std::endl;
  d.set(4,'o');
  d.print();
}
