#include <iostream>
using namespace std;

void cadena(char *&punt){
  int tam=0;
  char *tmp;
  char c;
  punt = new char[100];
  cout << "Ingrese su cadena: ";
  cin.get(c);
  while(c!=char(10)){
    *(punt+tam) = c;
    cin.get(c);
    tam++;
  }
  tmp = new char[tam];
  for(int i=0;i<tam;i++){
    *(tmp+i) = *(punt+i);
  }
  delete [] punt;
  punt = tmp;
}

void mayuscula(char *punt){
  int it=0;
  do {
    if(*(punt+it) >= 'a' && *(punt+it) <= 'z'){
      *(punt+it)-=32;
    }
    it++;
  } while(*(punt+it)!='\0');
}

int main(){
  char *cad;
  cadena(cad);
  mayuscula(cad);
  cout << cad << endl;
  delete [] cad;
}
