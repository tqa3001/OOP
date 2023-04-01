#include <iostream>
#include "./custom/queue.cpp"
#define MAX_AGE_YOUNG 30
#define BORROW_LIMIT 20
using namespace std;

// Abstraction: hiding complexity behind an interface which is a contract requiring certain methods to 
// be implemented. 
// Java has a thing called "interface" which essentially is an abstract class. 
// So in this example: Another dev who wants to use the Student class only needs to see
// AbstractStudent -> hides all complexity
class AbstractStudent {
  // virtual -> derive class has funct that overrides it
  virtual int addBook(int book_id) = 0; 
  virtual void expireBook() = 0; 
  virtual bool isEligibleForPromotion() = 0; // = 0 -> pure
};

class Student : AbstractStudent {
// Encapsulation: hiding data shared by many related functions by putting them into a class and make the data
// private, allowing it to be access only through defined functions 
private:
  string ID; 
  string Name; 
  int Age; 
  Queue<int> Books; 

public: 
  Student(string id, string name, int age) : ID(id), Name(name), Age(age) {}; 
  bool isOld() { return this->Age > MAX_AGE_YOUNG; }

  // Getters
  string getID() { return ID; } // or (*this).ID or this->ID
  string getName() { return Name; }
  int getAge() { return Age; }

  // Setters 
  int addBook(int book_id)  {
    if (Books.size() == BORROW_LIMIT) 
      return -1; 
    Books.push(book_id); 
    return Books.size(); 
  }
  void expireBook() {
    if (!Books.size())
      Books.pop(); 
  }

  // Comment this function -> won't compile. 
  bool isEligibleForPromotion() {
    return (Age >= 18 && Books.size() >= 5); 
  }
}; 

signed main() {
  Student A("a32by61v", "Quandale Dingle", 50); 
  cout << A.getID() << ',' << A.getAge() << ',' << A.getName() << '\n'; 
  cout << A.isEligibleForPromotion() << '\n'; 
  for (int i = 0; i < 5; i++) 
    A.addBook(i); 
  cout << A.isEligibleForPromotion() << '\n'; 
}