#include <iostream>
using namespace std;

template<unsigned int Num, unsigned int Div = Num-1>
struct Loop{
  static inline bool esPrimo(){
    return (Num%Div==0) ? false : Loop<Num, Div-1>::esPrimo();
  }
};
template<unsigned int Num>
struct Loop<Num, 1>{
  static inline bool esPrimo(){
    return true;
  }
};
template<>
struct Loop<0>{
  static inline bool esPrimo(){
    return false;
  }
};
template<>
struct Loop<1>{
  static inline bool esPrimo(){
    return false;
  }
};

int main(){
  cout << (Loop<1000>::esPrimo() ? "1000 es primo" : "1000 no es primo") << endl;
  cout << (Loop<4049>::esPrimo() ? "4049 es primo" : "4049 no es primo") << endl;
  cout << (Loop<2>::esPrimo() ? "2 es primo" : "2 no es primo") << endl;
  cout << (Loop<1>::esPrimo() ? "1 es primo" : "1 no es primo") << endl;
}
