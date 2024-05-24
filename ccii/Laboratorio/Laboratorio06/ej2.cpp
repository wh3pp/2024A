#include <iostream>
using namespace std;

double potencia(double bas,int exp){
  double res;
  if(exp==0){
    res = 1;
  }else{
    res = bas;
    int _exp = (exp < 0 ? exp*-1 : exp);
    for(int i=1; i<_exp; i++){
      res*=bas;
    }
    if(exp<0){
      res = 1/res;
    }
  }
  return res;
}

double convertir(const char *str){
  bool isint = true;
  double decimal=0;
  int itdec=-1;
  double signo = 1;
  while(*str != '\0'){
    if(*str=='-'){
      signo = -1;
    }else if(*str=='.'){
      isint = false;
    }else{
      if(isint==true){
        decimal *= 10;
        decimal += double(*str)-48;
      }else{
        decimal += (double(*str)-48)*potencia(10,itdec);
        itdec--;
      }
    }
    str++;
  }
  return decimal*signo;
}

class Nodo{
  public:
    virtual double operar() = 0;
    virtual ~Nodo () {}
};

class NumNodo : public Nodo{
    double num;
  public:
    NumNodo(double num) : num(num) {}
    double operar(){return num;}
};

class OperNodo : public Nodo{
  protected:
    Nodo *hizq;
    Nodo *hder;
  public:
    OperNodo(Nodo *hizq, Nodo *hder) : hizq(hizq), hder(hder) {}
    ~OperNodo(){delete hder; delete hizq;}
};

class SumaNodo : public OperNodo{
  public:
    SumaNodo(Nodo *hizq, Nodo *hder): OperNodo(hizq, hder) {}
    double operar(){return hizq->operar() + hder->operar();}
};

class RestaNodo : public OperNodo{
  public:
    RestaNodo(Nodo *hizq, Nodo *hder): OperNodo(hizq, hder) {}
    double operar(){return hizq->operar() - hder->operar();}
};

class MultNodo: public OperNodo{
  public:
    MultNodo(Nodo *hizq, Nodo *hder): OperNodo(hizq, hder) {}
    double operar(){return hizq->operar() * hder->operar();}
};

class DivNodo : public OperNodo{
  public:
    DivNodo(Nodo *hizq, Nodo *hder): OperNodo(hizq, hder) {}
    double operar(){return hizq->operar() / hder->operar();}
};

int main(){
  Nodo *s1 = new NumNodo(10.6);
  Nodo *s2 = new NumNodo(15.4);
  Nodo *s3 = new SumaNodo(s1,s2);
  Nodo *s4 = new NumNodo(-4);
  Nodo *s5 = new RestaNodo(s3,s4);
  cout << s5->operar() << endl;
}
