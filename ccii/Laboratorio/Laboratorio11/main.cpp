#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
using namespace std;

class ListaEnlazada {
  friend ostream& operator<<(ostream& os, const ListaEnlazada& lista);
private:
  double x, y;
  ListaEnlazada* sig;
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
  ListaEnlazada* nuevo = new ListaEnlazada(x, y);
  ListaEnlazada* anterior = nullptr;
  ListaEnlazada* actual = this;
  while (actual != nullptr && y > actual->y) {
    anterior = actual;
    actual = actual->sig;
  }
  if (anterior == nullptr) {
    nuevo->sig = this;
    *this = *nuevo;
  } else {
    anterior->sig = nuevo;
    nuevo->sig = actual;
  }
}


bool ListaEnlazada::search(double x, double y){
  if(this->sig == nullptr){
    return false;
  }
  if(this->sig->y == y && this->sig->x == x){
    return true;
  }
  return this->sig->search(x, y);
}

void ListaEnlazada::eliminar(double x, double y){
  if(this->sig == nullptr){
    return;
  }
  if(this->sig->x == x && this->sig->y == y){
    ListaEnlazada* tmp = this->sig;
    this->sig = tmp->sig;
    delete tmp;
  }else{
    this->sig->eliminar(x, y);
  }
}
ostream& operator<<(ostream& output, const ListaEnlazada& lista){
  const ListaEnlazada* tmp = &lista;
  while (tmp != nullptr){
    output << fixed << setprecision(6) << tmp->x << ", " << tmp->y << endl;
    tmp = tmp->sig;
  }
  return output;
}
int main(){
  ifstream file("DataGen.txt");
  ofstream output("output.txt");
  ListaEnlazada* lista = new ListaEnlazada();
  if(!file){
    cout << "No se puede abrir el archivo" << endl;
    return 1;
  }
  double x,y;
  char comma;
  //int count = 1;
  const auto start = chrono::high_resolution_clock::now();
  while(file >> x >> comma >> y){
    lista->insert(x,y);
    /*if(count == 100){
      break;
    }
    count++;*/
  }
  const auto end = chrono::high_resolution_clock::now();
  const chrono::duration<double> diff = end - start;
  cout << "Tiempo en ordenar el archivo usando ListaEnlazada: " << diff.count() << '\n';
/*
  cout << lista->search(0.106319,0.984121) << endl;
  lista->eliminar(0.610445,0.622324);
  lista->eliminar(0.106319,0.984121);
  cout << lista->search(0.106319,0.984121) << endl;*/
  output << *lista;
  output.close();
  file.close();
  delete lista;
}

