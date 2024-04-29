#include <iostream>
using namespace std;

void reemplazar(char *&punt){
  int it=0;
  char vocales[10] = {65,69,73,79,85,97,101,105,111,117};
  while ( *(punt+it) != '\0'){
    for(char voc : vocales) {
      if(*(punt+it) == voc){
        *(punt+it) = 'X';
      }
    }
    it++;
  }
}
int main(){
  char *texto = new char[205]{
    //Llevaba una larga capa formada por recuadros negros,
    //rojos y amarillos. Era alto, delgado y con brillantes 
    //ojos azules, portaba una sonrisa dirigida a unos y otros,
    //como si se hallara entre viejos amigos.
    'L', 'l', 'e', 'v', 'a', 'b', 'a', ' ', 'u', 'n', 'a', ' ',
    'l', 'a', 'r', 'g', 'a', ' ', 'c', 'a', 'p', 'a', ' ', 'f',
    'o', 'r', 'm', 'a', 'd', 'a', ' ', 'p', 'o', 'r', ' ', 'r',
    'e', 'c', 'u', 'a', 'd', 'r', 'o', 's', ' ', 'n', 'e', 'g',
    'r', 'o', 's',',', ' ', 'r', 'o', 'j', 'o', 's', ' ', 'y',
    ' ', 'a', 'm', 'a', 'r', 'i', 'l', 'l', 'o', 's', '.', ' ',
    'E', 'r', 'a', ' ', 'a', 'l', 't', 'o', ',', ' ', 'd', 'e',
    'l', 'g', 'a', 'd', 'o', ',', ' ', 'y', ' ', 'c', 'o', 'n',
    ' ', 'b', 'r', 'i', 'l', 'l', 'a', 'n', 't', 'e', 's', ' ',
    'o', 'j', 'o', 's', ' ', 'a', 'z', 'u', 'l', 'e', 's', ',',
    ' ', 'p', 'o', 'r', 't', 'a', 'b', 'a', ' ', 'u', 'n', 'a',
    ' ', 's', 'o', 'n', 'r', 'i', 's', 'a', ' ', 'd', 'i', 'r',
    'i', 'g', 'i', 'd', 'a', ' ', 'a', ' ', 'u', 'n', 'o', 's',
    ' ', 'y', ' ', 'o', 't', 'r', 'o', 's', ',', ' ', 'c', 'o',
    'm', 'o', ' ', 's', 'i', ' ', 's', 'e', ' ', 'h', 'a', 'l',
    'l', 'a', 'r', 'a', ' ', 'e', 'n', 't', 'r', 'e', ' ', 'v',
    'i', 'e', 'j', 'o', 's', ' ', 'a', 'm', 'i', 'g', 'o', 's',
    '.'
};
  reemplazar(texto);
  cout << texto << endl;
  delete [] texto;
}
