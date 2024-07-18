#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

int** sumar(int** a, int** b, int fil, int col){
  int **tmp = new int*[fil];
  for(int i=0; i<fil; i++){
    tmp[i] = new int[col];
    for(int j=0; j<col; j++){
      tmp[i][j] = a[i][j] + b[i][j];
    }
  }
  return tmp;
}

int** multiplicar(int** a, int** b, int afil, int acol,int bcol){
  int **tmp = new int*[afil];
  for(int i=0; i<afil; i++){
    tmp[i] = new int[bcol];
    for(int j=0; j<bcol; j++){
      tmp[i][j] = 0;
      for(int k=0; k<acol; k++){
        tmp[i][j] += a[i][k] + b[k][j];
      }
    }
  }
  return tmp;
}

int main(){
  int** m1 = new int*[1000];
  int** m2 = new int*[1000];
  srand(time(NULL));
  for(int i=0; i<1000; i++){
    m1[i] = new int[1000];
    m2[i] = new int[1000];
    for(int j=0; j<1000; j++){
      m1[i][j] = rand()%100;
      m2[i][j] = rand()%100;
    }
  }
  const auto startSum = chrono::high_resolution_clock::now();
  int** sum = sumar(m1,m2,1000,1000);
  const auto endSum = chrono::high_resolution_clock::now();
  const chrono::duration<double> diffSum = endSum - startSum;
  cout << "El tiempo de ejecución de la suma: " << diffSum.count() << endl;
  const auto startMul = chrono::high_resolution_clock::now();
  int** mul = multiplicar(m1,m2,1000,1000,1000);
  const auto endMul = chrono::high_resolution_clock::now();
  const chrono::duration<double> diffMul = endMul - startMul;
  cout << "El tiempo de ejecución de la multiplicación: " << diffMul.count() << endl;
  for(int i=0; i<1000; i++){
    delete [] m1[i];
    delete [] m2[i];
    delete [] sum[i];
    delete [] mul[i];
  }
  delete [] m1;
  delete [] m2;
  delete [] sum;
  delete [] mul;
}
