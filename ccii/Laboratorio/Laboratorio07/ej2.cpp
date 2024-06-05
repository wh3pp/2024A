#include <iostream>
using namespace std;

int mcm(int a, int b){
  if(a==b){
    return a;
  }
  int it=1;
  int max = a>b ? a : b;
  int min = b>a ? a : b;
  while(max*it%min != 0){
    it++;
  }
  return max*it;
}

class Fraccion{
    int nume, deno;
  public:
    Fraccion(){}
    Fraccion(int nume, int deno) : nume(nume), deno(deno){}
    Fraccion operator*(const Fraccion& a){
      return Fraccion(this->nume * a.nume, this->deno * a.deno);
    }
    Fraccion operator/(const Fraccion& a){
      return Fraccion(this->nume * a.deno, this->deno * a.nume);
    }
    Fraccion operator+(const Fraccion& a){
      int m = mcm(this->deno, a.deno);
      return Fraccion(this->nume*(m/this->deno) + a.nume*(m/a.deno), m);
    }
    Fraccion operator-(const Fraccion& a){
      int m = mcm(this->deno, a.deno);
      return Fraccion(this->nume*(m/this->deno) - a.nume*(m/a.deno), m);
    }
    friend ostream& operator<<(ostream& output, const Fraccion& a);
};

ostream& operator<<(ostream& output, const Fraccion& a){
  output << a.nume << "/" << a.deno;
  return output;
}

int main(){
  Fraccion a(3,20);
  Fraccion b(9,2);
  cout << a << " + " << b << " = " << a + b<< endl;
  cout << a << " - " << b << " = " << a - b<< endl;
  cout << a << " * " << b << " = " << a * b<< endl;
  cout << a << " / " << b << " = " << a / b<< endl;
}
