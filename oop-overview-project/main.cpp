#include <iostream>
#define MAX_AGE_YOUNG 30
using namespace std;

class Student {

private:
  string ID; 
  string Name; 
  int Age; 

public: 
  Student(string id, string name, int age) : ID(id), Name(name), Age(age) {}; 
  
  bool isOld() { return Age > MAX_AGE_YOUNG; }

}; 

signed main() {
  ostream outFile(); 
  outFile.open()
  Student A("a32by61v", "Quandale Dingle", 50); 
  cout << A.isOld() << '\n'; 
}