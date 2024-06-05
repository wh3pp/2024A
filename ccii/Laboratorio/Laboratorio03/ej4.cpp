#include <iostream>
using namespace std;

void concatenar(char *&cad1, char *cad2){
  int tam1=0,tam2=0;
  while(*(cad1+tam1) != '\0' || *(cad2+tam2) !='\0'){
    if(*(cad1+tam1) !='\0'){
      tam1++;
    }
    if(*(cad2+tam2) != '\0'){
      tam2++;
    }
  }
  char *tmp = new char[tam1+tam2];
  for(int i=0; i<tam1; i++){
    *(tmp+i) = *(cad1+i);
  }
  for(int i=tam1; i<tam1+tam2; i++){
    *(tmp+i) = *(cad2+i-tam1);
  }
  delete [] cad1;
  cad1 = tmp;
}

int main(){
  char *cad1  = new char[5]{'H','e','l','l','o'};
  char *cad2 = new char[6]{' ','W','o','r','l','d'};
  concatenar(cad1,cad2);
  cout << cad1 << endl;
  cout << cad2 << endl;
  delete [] cad1;
  delete [] cad2;
}
