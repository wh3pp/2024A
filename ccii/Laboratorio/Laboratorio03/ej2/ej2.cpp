#include <iostream>
using namespace std;

int comparar(char *cad1, char *cad2){
  int tam=0;
  while(*(cad1+tam) != '\0' && *(cad2+tam) != '\0'){
    if(*(cad1+tam) < *(cad2+tam)){
      return -1;
    }
    if(*(cad1+tam) > *(cad2+tam)){
      return 1;
    }
    tam++;
  }
  if(*(cad1+tam) != '\0'){
    return 1;
  }
  if(*(cad2+tam) != '\0'){
    return -1;
  }
  return 0;
}

int main(){
  char *cad1 = new char[10]{'H','o','l','a',' ','M','u','n','d','o'};
  char *cad2 = new char[11]{'H','e','l','l','o',' ','W','o','r','l','d'};
  //char *cad2 = new char[10]{'H','o','l','a',' ','M','u','n','d','o'};
  //char *cad1 = new char[12]{'H','e','l','l','o',' ','w','o','r','l','d','!'};

  int res = comparar(cad1,cad2);
  if(res == -1){
    cout << "\"" << cad1 << "\" es menor lexicograficamente a \"" << cad2 << "\"";
  } else if(res == 1){
    cout << "\"" << cad1 << "\" es mayor lexicograficamente a \"" << cad2 << "\"";
  } else {
    cout << "\"" << cad1 << "\" es igual lexicograficamente a " << cad2 << "\"";
  }
  cout << endl;
  delete [] cad1;
  delete [] cad2;
}
