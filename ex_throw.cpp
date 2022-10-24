#include<iostream>
#include<cstdlib>
#include<exception>
using namespace std;

void my_terminator(){
  cout << "I was stopped.\n";
  abort();
}
int main(){
  set_terminate(my_terminator);
  try{
    cout << "This will print.\n";
    throw 100;
  }catch(double i) {
    cout << i << " is caught.\n";
    return 1;
  }
  return 0;
}