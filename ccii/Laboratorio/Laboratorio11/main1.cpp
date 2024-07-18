#include <iostream>
#include <fstream>
#include <iomanip>
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
void ListaEnlazada::insert(double x, double y){
  if(this->x == 0 && this->y==0 && this->sig==nullptr){
    *this = ListaEnlazada(x,y);
  }else if(this->y > y){
    ListaEnlazada* tmp = new ListaEnlazada(this->x,this->y);
    *this = ListaEnlazada(x,y);
    this->sig = tmp;
  }else if(this->sig == nullptr || this->sig->y > y){
    ListaEnlazada* tmp = new ListaEnlazada(x,y);
    tmp->sig = this->sig;
    this->sig = tmp;
  }else{
    this->sig->insert(x, y);
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
  int count=0;
  while(file >> x >> comma >> y){
    lista->insert(x,y);
    if(count == 10000){
      break;
    }
    count ++;
  }
  file.close();
  output << *lista;
  output.close();
  delete lista;
}

