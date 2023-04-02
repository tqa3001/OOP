#include <iostream>
#include <vector>
#include <string> 
#include "./custom/queue.cpp"
#define MAX_AGE_YOUNG 30
#define BORROW_LIMIT 20
using namespace std;

class Document {
private:
  string Author;
  string Title; 
  int DocumentID; 
public: 
  Document(string author="", string title="", int id=-1) : Author(author), Title(title), DocumentID(id) {};
  string getAuthor() { return Author; }
  string getTitle() { return Title; } 
  int getID() { return DocumentID; }
};

class Book : Document {
private: 
  string Summary; 
  vector<pair<string, double> > Reviews; 
public: 
  // Reusing Document's constructor
  Book(string author="", string title="", int id=-1, string summary = "") 
    : Document(author, title, id) 
    { Summary = summary; }

  // getter 
  string getSummary() { return Summary; }

  double AvgRating() {
    if (Reviews.empty()) 
      return -1; 
    double result = 0; 
    for (auto entry : Reviews) 
      result += entry.second; 
    return result / (int)Reviews.size(); 
  }

  void addReview(string review, double rating) { Reviews.push_back({review, rating}); }

  string getBookInfo() {
    const int WIDTH = 50; 
    string data = 
      "Title: " + getTitle() + "\n\n" + 
      "Author: " + getAuthor() + "\n\n" + 
      "ID: " + to_string(getID()) + "\n\n" + 
      "Summary: " + Summary + "\n\n" + 
      "Average rating: " + to_string(AvgRating()); 
    string break_row; 
    for (int i = 0; i < WIDTH; i++) 
      break_row += "="; 
    break_row += "\n"; 
    string table = break_row + "|"; 
    int cur = 1; 
    for (char c : data) {
      if (c == '\n') {
        while (cur < WIDTH - 1) {
          table += " "; 
          cur++; 
        }
        table += "|\n|"; 
        cur = 1; 
      } else {
        if (cur == WIDTH - 1) {
          table += "|\n|"; 
          cur = 1; 
        }
        table += c; 
        cur++; 
      }
    }
    while (cur < WIDTH - 1) { table += " "; cur++; }
    table += "|\n" + break_row; 
    return table; 
  }
}; 

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
  Book book1("Kuspit", "The End of Art", 1000, "A book I have never read"); 
  book1.addReview("Pretty good", 5); 
  book1.addReview("Informative read, but a bit dry", 3); 
  book1.addReview("Terrible!", 1); 
  cout << "New book info: \n"; 
  cout << book1.getBookInfo() << '\n'; 
}