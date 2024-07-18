#include <iostream>
#include <functional>
using namespace std;

template<int num, int divisor = num - 1>
class Loop {
public:
  template <typename FuncType>
  static inline void Do(FuncType func) {
    Loop<num, divisor - 1>::Do(func);
    func(num, divisor);
  }
};

template<int num>
class Loop<num, 1> {
public:
  template <typename FuncType>
  static inline void Do(FuncType) {}
};

void esPrimo(int i, int j) {
  cout << "esPrimo(" << i << ", " << j << ")" << endl;
}

int main() {
  Loop<20>::Do(esPrimo);
  return 0;
}

