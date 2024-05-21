#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class nodo {
  public:
    T data;
    vector <nodo *> hijos;
    nodo(T data): data(data) {}
};

template <typename T>
class ArbolBinario {
  public:
    nodo <T> *raiz;
};

int main(){
  nodo ar(5);
}

