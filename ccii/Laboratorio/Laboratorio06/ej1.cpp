#include <iostream>
using namespace std;
class Superior {
  public:
    virtual void print(){
      cout << "Superior" << endl;
    }
};

class Inferior : public Superior{
  public:
    void print(){
      cout << "Inferior" << endl;
     // Superior::print();
    }
};

int main(){
  Inferior infe;
  infe.print();
  infe.Superior::print();
}
