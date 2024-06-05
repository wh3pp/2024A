#include <iostream>
using namespace std;

class Fecha{
  friend ostream& operator << (ostream& output, const Fecha& a);
  private:
    int dia, mes, año;
    int dias[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    void incrementarFecha();
    void decrementarFecha();
  public:
    Fecha() : dia(1), mes(1), año(1900){}
    Fecha(int dia, int mes, int año);
    void setFecha(int dia, int mes, int año);
    bool esBisiesto();
    bool esUltimoDia();
    Fecha& operator++();
    Fecha& operator++(int);
    Fecha& operator--();
    Fecha& operator--(int);
    //Fecha& operator+=(const Fecha& a);
};

void Fecha::setFecha(int dia, int mes, int año){
  if(mes>=1 && mes<=12){
    this->mes = mes;
  }else{
    cout << "Mes inválido, el rango aceptado es [1-12]...Utilizando el constructor por defecto\n";
    *this = Fecha();
    return;
  }
  if(año>=0){
    this->año = año;
  }else{
    cout << "Año inválido, el rango aceptado es >= 0...Utilizando el constructor por defecto\n";
    *this = Fecha();
    return;
  }
  if((esBisiesto() && mes == 2 && dia>=1 && dia <=29) || (dia>=1 && dia<=dias[mes-1])){
    this->dia = dia;
  }else{
    cout << "Día inválido, fuera del rango de días...Utilizando el constructor por defecto\n";
    *this = Fecha();
    return;
  }
}

Fecha::Fecha(int dia, int mes, int año){
  setFecha(dia,mes,año);
}

bool Fecha::esBisiesto(){
  if(año % 400 == 0 || (año % 100!=0 && año % 4 == 0)){
    return true;
  }
  return false;
}

bool Fecha::esUltimoDia(){
  if(esBisiesto() && mes==2){
    if(dia == 29){
      return true;
    }
  }else{
    if(dia == dias[mes-1]){
      return true;
    }
  }
  return false;
}

void Fecha::incrementarFecha(){
  if(esUltimoDia()){
    this->dia=1;
    if(this->mes==12){
      this->año++;
      this->mes=1;
    }else{
      this->mes++;
    }
  }else{
    this->dia++;
  }
}

void Fecha::decrementarFecha(){
  if(this->dia ==1){
    if(this->mes == 1){
      this->año--;
      this->mes = 12;
    }else{
      if(this->mes == 3 && esBisiesto()){
        this->dia = 29;
      }else{
        this->dia = dias[mes-2];
      }
      this->mes--;
    }
      
  }else{
    this->dia--;
  }
}

Fecha& Fecha::operator++(int){
  incrementarFecha();
  return *this;
}

Fecha& Fecha::operator++(){
  incrementarFecha();
  return *this;
}

Fecha& Fecha::operator--(){
  decrementarFecha();
  return *this;
}
Fecha& Fecha::operator--(int){
  decrementarFecha();
  return *this;
}
/*
Fecha& Fecha::operator+=(const Fecha& a){
  int _año = this->año + a.año;
  int _dia = this->dia;
  for(int i=0; i<this->mes-1;i++){
    _dia+=dias[i];
  }
  for(int i=0; i<a.mes-1;i++){
    _dia+=dias[i];
  }
*/
ostream& operator << (ostream& output, const Fecha& a){
  const char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "setiembre", "octubre", "noviembre", "diciembre"};
  output << a.dia << " de " << meses[a.mes-1] << " de " << a.año;
  return output;
}

int main(){
  Fecha def(29,2,2000);
  cout << def << endl;
  ++def;
  cout << def << endl;
  def++;
  cout << def << endl;
  def--;
  cout << def << endl;
  --def;
  cout << def << endl;
}
