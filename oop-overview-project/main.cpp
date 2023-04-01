#include <iostream>
// #include "./data_structures.cpp"
#define MAX_AGE_YOUNG 30
#define BORROW_LIMIT 20
using namespace std;

class Student {
private:
  string ID; 
  string Name; 
  int Age; 
  int NumberOfBooks; 
  int BorrowedBookIDs[BORROW_LIMIT]; 
public: 
  Student(string id, string name, int age) : ID(id), Name(name), Age(age) {
    NumberOfBooks = 0; 
  }; 
  bool isOld() { return this->Age > MAX_AGE_YOUNG; }
  // getters
  string getID() { return this->ID; } // or (*this).ID; 
  string getName() { return this->Name; }
  int getAge() { return this->Age; }
  // setters 
  int addBook(int book_id)  {
    if (NumberOfBooks == BORROW_LIMIT) 
      return -1; 
    this->BorrowedBookIDs[NumberOfBooks++] = book_id; 
    return NumberOfBooks; 
  }
  int expireBook() {
    return -1; 
  }
}; 

signed main() {
  Student A("a32by61v", "Quandale Dingle", 50); 
  cout << A.isOld() << '\n'; 
  // TODO: a::b vs a->b vs a.b
}