#include<iostream>
#include<fstream>
using namespace std;

/*
 * @brief: test on files 
 */
int main(){
  fstream rwriter("hello");
  //fstream readwrite("hello");
  
  if(!rwriter) cout << "hello wasnt found for write." << endl;
  //if(!readwrite) cout << "hello wasnt found." << endl;

  // ifstream reader("hello");
  // if(!reader) cout << "hello wasnt found for read." << endl;

  rwriter.write("hello world", 11);
  // readwrite.write("hey, world", 10);
  rwriter.seekg(SEEK_SET);
  char str[22];
  rwriter.read(str, 11);
  // readwrite.close();
  rwriter.close();
  // reader.close();
  // remove("hello");
  cout << str << endl;
  return 0;
}