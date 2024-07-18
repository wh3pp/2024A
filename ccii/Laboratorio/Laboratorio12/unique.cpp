#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <memory>
using namespace std;

class ListaEnlazada {
    friend ostream& operator<<(ostream& os, const ListaEnlazada& lista);
  private:
    double x, y;
    unique_ptr<ListaEnlazada> sig; 
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

void ListaEnlazada::insert(double x, double y) {
  unique_ptr<ListaEnlazada> nuevo = make_unique<ListaEnlazada>(x, y);
  ListaEnlazada* anterior = nullptr;
  ListaEnlazada* actual = this->sig.get();
  while (actual != nullptr && y > actual->y) {
    anterior = actual;
    actual = actual->sig.get();
  }
  if (anterior == nullptr) {
    nuevo->sig = move(this->sig);
    this->sig = move(nuevo);
  } else {
    nuevo->sig = move(anterior->sig);
    anterior->sig = move(nuevo);
  }
}

bool ListaEnlazada::search(double x, double y) {
  ListaEnlazada* actual = this->sig.get();
  while (actual != nullptr) {
    if (actual->x == x && actual->y == y) {
      return true;
    }
    actual = actual->sig.get();
  }
  return false;
}

void ListaEnlazada::eliminar(double x, double y) {
  ListaEnlazada* actual = this->sig.get();
  ListaEnlazada* anterior = nullptr;
  while (actual != nullptr) {
    if (actual->x == x && actual->y == y) {
      if (anterior == nullptr) {
        this->sig = move(actual->sig);
      } else {
        anterior->sig = move(actual->sig);
      }
      return;
    }
    anterior = actual;
    actual = actual->sig.get();
  }
}

ostream& operator<<(ostream& output, const ListaEnlazada& lista) {
  ListaEnlazada* tmp = lista.sig.get();
  while (tmp != nullptr) {
    output << fixed << setprecision(6) << tmp->x << ", " << tmp->y << endl;
    tmp = tmp->sig.get();
  }
  return output;
}

int main() {
  ifstream file("DataGen.txt");
  ofstream output("output.txt");
  unique_ptr<ListaEnlazada> lista = make_unique<ListaEnlazada>(); 
  if (!file) {
    cout << "No se puede abrir el archivo" << endl;
    return 1;
  }

  double x, y;
  char comma;
  const auto start = chrono::high_resolution_clock::now();
  while (file >> x >> comma >> y) {
    lista->insert(x, y);
  }
  const auto end = chrono::high_resolution_clock::now();
  const chrono::duration<double> diff = end - start;
  cout << "Tiempo en ordenar los datos usando unique_ptr: " << diff.count() << " segundos\n";
  output << *lista;
  output.close();
  file.close();
}

