#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <memory> 
using namespace std;

class ListaEnlazada{
    friend ostream& operator<<(ostream& os, const ListaEnlazada& lista);
  private:
    double x, y;
    shared_ptr<ListaEnlazada> sig; 
  public:
    ListaEnlazada();
    ListaEnlazada(double x, double y);
    void insert(double x, double y);
    bool search(double x, double y);
    void eliminar(double x, double y);
};

ListaEnlazada::ListaEnlazada(double x, double y){
  this->x = x;
  this->y = y;
  this->sig = nullptr;
}

ListaEnlazada::ListaEnlazada(){
  this->x = 0;
  this->y = 0;
  this->sig = nullptr;
}

void ListaEnlazada::insert(double x, double y){
  shared_ptr<ListaEnlazada> nuevo = make_shared<ListaEnlazada>(x, y); 
  shared_ptr<ListaEnlazada> anterior = nullptr;
  shared_ptr<ListaEnlazada> actual = this->sig; 
  while (actual != nullptr && y > actual->y){
    anterior = actual;
    actual = actual->sig;
  }
  if (anterior == nullptr){
    nuevo->sig = this->sig; 
    this->sig = nuevo;
  } else{
    anterior->sig = nuevo;
    nuevo->sig = actual;
  }
}

bool ListaEnlazada::search(double x, double y){
  shared_ptr<ListaEnlazada> tmp = this->sig;
  while (tmp != nullptr){
    if (tmp->x == x && tmp->y == y){
      return true;
    }
    tmp = tmp->sig;
  }
  return false;
}

void ListaEnlazada::eliminar(double x, double y){
  shared_ptr<ListaEnlazada> actual = this->sig;
  shared_ptr<ListaEnlazada> anterior = nullptr;
  while (actual != nullptr){
    if (actual->x == x && actual->y == y){
      if (anterior == nullptr){
        this->sig = actual->sig;
      } else{
        anterior->sig = actual->sig;
      }
      return;
    }
    anterior = actual;
    actual = actual->sig;
  }
}

ostream& operator<<(ostream& output, const ListaEnlazada& lista){
  shared_ptr<ListaEnlazada> tmp = lista.sig;
  while (tmp != nullptr){
    output << fixed << setprecision(6) << tmp->x << ", " << tmp->y << endl;
    tmp = tmp->sig;
  }
  return output;
}

int main(){
  ifstream file("DataGen.txt");
  //ofstream output("output.txt");
  shared_ptr<ListaEnlazada> lista = make_shared<ListaEnlazada>(); 

  if (!file){
    cout << "No se puede abrir el archivo" << endl;
    return 1;
  }

  double x, y;
  char comma;
  const auto start = chrono::high_resolution_clock::now();
  while (file >> x >> comma >> y){
    lista->insert(x, y);
  }
  const auto end = chrono::high_resolution_clock::now();
  const chrono::duration<double> diff = end - start;
  cout << "Tiempo en ordenar el archivo usando shared_ptr: " << diff.count() << '\n';
  //output << *lista;
  //output.close();
  file.close();
}

