#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyList{
    vector<T> data;
  public:
    MyList& operator,(const T& a){
      data.push_back(a);
      return *this;
    }
    vector<T> getVector() const{return data;}
};

int main(){
  MyList<int> mylist;
  mylist, 10, 12, 10, 13, 13, 139, 13;
  for(int ele : mylist.getVector()){
    cout << ele << "  ";
  }
  cout << endl;
}
