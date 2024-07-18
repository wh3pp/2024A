#include <iostream>
using namespace std;

template<int Tam, typename T, const T* Arr>
struct Loop{
  static inline int buscar(T valor){
    return (Arr[Tam-1] == valor) ? Tam-1 : Loop<Tam-1,T,Arr>::buscar(valor);
  }
};

template<typename T, const T* Arr>
struct Loop<0, T, Arr>{
  static inline int buscar(T valor){
    return -1;
  }
};

int main(){
  static constexpr int arr[7] = {10, 20, 30, 40, 50, 60, 70};
  static constexpr char arr2[7] = {'o', 'u', 'v', 'b', 'a', 'f', 'g'};
  cout << "30 se encuentra en el índice: " << Loop<7, int, arr>::buscar(1) << endl;
  cout << "10 se encuentra en el índice: " << Loop<7, int, arr>::buscar(10) << endl;
  cout << "b se encuentra en el índice: " << Loop<7, char, arr2>::buscar('b') << endl;
}
