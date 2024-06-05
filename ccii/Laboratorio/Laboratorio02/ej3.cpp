#include <iostream>
using namespace std;
void func(){
  int num = 8;
  int *p = new int(num);
  cout << "\tVariable\nValor: " << num << endl;
  cout << "Direccion: " << &num << endl;
  cout << "\tPuntero\nValor: " << *p << endl;
  cout << "Direccion: " << &p << endl;
  delete p;
}
int main(){
  func();
}
