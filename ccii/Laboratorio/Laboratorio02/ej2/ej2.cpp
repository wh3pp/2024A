#include <iostream>
using namespace std;

void conversion(int *&num){
  num=NULL;
}
int main(){
  int *num = new int(8);
  cout << num << endl;
  conversion(num);
  cout << num << endl;
}
