#include <iostream>
using namespace std;
int main(){
  int *x = new int,*y = new int;
  cout << "Primer Valor: ";
  cin >> *x;
  cout << "Segundo Valor: ";
  cin >> *y;
  cout << "Producto: " << *x**y <<endl;
  delete x;
  delete y;
}
