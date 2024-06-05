#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector<T>& operator++(vector<T>& data, int){
  for(T ele : data){
    cout << ele << "  ";
  }
  cout << endl;
  return data;
}

template <typename T>
vector<T>& operator++(vector<T>& data){
  for(T ele : data){
    cout << ele << "  ";
  }
  cout << endl;
  return data;
}

int main(){
  vector<int> a={10,20,10,20,301,203,1,2,0,3};
  a++;
  ++a;
}
