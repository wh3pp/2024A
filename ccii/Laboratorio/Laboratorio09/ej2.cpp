#include <iostream>
#include <vector>
using namespace std;

class Observer{
  public:
    virtual void update(const char* message, const char* sender) = 0; 
};

class Subject{
  public:
    virtual void send(const char* message, const char* sender) = 0;
    virtual void registerUser(Observer* observer) = 0;
};

class MyChat : public Subject{
    vector<Observer*> observers;
  public:
    void registerUser(Observer* observer){
      observers.push_back(observer);
    }
    void send(const char* message, const char* sender){
      for(Observer* observer : observers){
        observer->update(message, sender);
      }
    }
};

class Alumno : public Observer{
    const char* name;
    vector<const char*> messages;
  public:
    Alumno(const char* name) : name(name) {};
    void update(const char* message, const char* sender){
      messages.push_back(message);
      cout << sender << " dice: " << message << " a " << name << std::endl;
    }
    void showHistorial() const{
      cout << "-------------------------------------" << endl;
      cout << "Historial de: " << name << endl;
      for(const char* msj : messages){
        cout << msj << endl;
      }
    }
};


int main() {
  MyChat chat;

  Alumno alumno1("Jesus");
  Alumno alumno2("Sofia");
  chat.registerUser(&alumno1);
  chat.registerUser(&alumno2);

  chat.send("Como estan?", "Profesor");
  chat.send("se hace envio de sus tareas", "Profesor");
  chat.send("y de sus notas", "Profesor");

  alumno1.showHistorial();
  alumno2.showHistorial();
}

