#include <iostream>
#include <vector>
#include <string> 
#include <cassert>
#include "./custom/queue.cpp"
#define WINDOW_WIDTH 50
#define MAX_AGE_YOUNG 30
#define BORROW_LIMIT 20
using namespace std;

/**
 * Base class for documents
*/
class Document {
private:
  string Author;
  string Title; 
protected:  // can be access directly by derived classes 
  int DocumentID; 
public: 
  Document(string author="", string title="", int id=-1) : Author(author), Title(title), DocumentID(id) {};
  string getAuthor() { return Author; }
  string getTitle() { return Title; } 
  int getID() { return DocumentID; }
  virtual string getInfo(string data="") {
    data = 
      "Title: " + getTitle() + "\n" + 
      "Author: " + getAuthor() + "\n" + 
      "ID: " + to_string(DocumentID) + "\n\n" +
      data; 
    string break_row; 
    for (int i = 0; i < WINDOW_WIDTH; i++) 
      break_row += "="; 
    break_row += "\n"; 
    string table = break_row + "|"; 
    int cur = 1; 
    for (char c : data) {
      if (c == '\n') {
        while (cur < WINDOW_WIDTH - 1) {
          table += " "; 
          cur++; 
        }
        table += "|\n|"; 
        cur = 1; 
      } else {
        if (cur == WINDOW_WIDTH - 1) {
          table += "|\n|"; 
          cur = 1; 
        }
        table += c; 
        cur++; 
      }
    }
    while (cur < WINDOW_WIDTH - 1) { table += " "; cur++; }
    table += "|\n" + break_row; 
    return table; 
  }
};

/**
 * Book  
*/
class Book : public Document {  // keyword public is important
private: 
  string Summary; 
  vector<pair<string, double> > Reviews;  // well this can be seen as Composition
public: 
  // Reusing Document's constructor
  Book(string author="", string title="", int id=-1, string summary = "") 
    : Document(author, title, id) 
      { Summary = summary; }

  // Getters
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

  string getInfo(string data="") {
    data += 
      (string) "Type: Paper\n" +
      "Summary: " + Summary + "\n" + 
      "Average rating: " + to_string(AvgRating()); 
    return Document::getInfo(data); 
  }
}; 

/**
 * Paper
 * Assumption: each paper is written by 1 author (not accurate)
 * Or we can write multiple authors in the author field.
*/
class Paper : public Document {
private: 
  int Year; 
  // Aggregation
  vector<Paper*> References, Responses; 
  Paper* ParentPaper; 
public: 
  Paper(string author="", string title="", int id=-1, 
    int year=-1, vector<Paper*> refs=vector<Paper*>(), Paper* parent=NULL) 
    : Document(author, title, id), Year(year), References(refs) {
        ParentPaper = NULL; 
        if (parent != NULL) {
          respondTo(parent); 
          parent->addToResponses(this); 
        } 
      } 
  int getYear() { return Year; }
  void addToResponses(Paper* paper) { References.push_back(paper); }
  void respondTo(Paper* parent) { 
    assert(ParentPaper == NULL);
    assert(Year >= parent->getYear()); 
    (*parent).addToResponses(this); 
    ParentPaper = parent; 
  }
  string shortForm() { return getTitle() + ", " + getAuthor() + ", " + to_string(Year); }
  Paper* isReponseTo() { return ParentPaper; }
  string getInfo(string data="") { 
    // without "data=..", the compiler won't register this as reimplementation of Document::getInfo()
    data +=
      (string) "Responding to: " + (ParentPaper == NULL ? "None" : ParentPaper->shortForm()) + "\n" + 
      "References:\n"; 
    for (auto ref : References) 
      data += "- " + ref->shortForm() + "\n"; 
    data += "Responses to this paper:\n"; 
    for (auto resp : Responses) 
      data += "- " + resp->shortForm() + "\n"; 
    return Document::getInfo(data); 
  }
}; 

/**
 * Abstraction: hiding complexity behind an interface which is a contract requiring certain methods to
 * be implemented. 
 * Java has a thing called "interface" which essentially is an abstract class. 
 * So in this example: Another dev who wants to use the Student class only needs to see
 * AbstractStudent -> hides all complexity
*/

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
  // For more modularity: put each unit in a class in the /tests folder
  // Test Student 
  Student A("a32by61v", "Quandale Dingle", 50); 
  cout << A.getID() << ',' << A.getAge() << ',' << A.getName() << '\n'; 
  cout << A.isEligibleForPromotion() << '\n'; 
  for (int i = 0; i < 5; i++) 
    A.addBook(i); 
  cout << A.isEligibleForPromotion() << '\n'; 
  
  // Test Book
  Book book1("Kuspit", "The End of Art", 1000, "A book I have never read"); 
  book1.addReview("Pretty good", 5); 
  book1.addReview("Informative read, but a bit dry", 3); 
  book1.addReview("Terrible!", 1); 
  cout << "New book info: \n"; 
  cout << book1.getInfo() << '\n'; 
  cout << "I can getAuthor() only because it's public inheritance: " << book1.getAuthor() << '\n'; 

  // Test Paper
  Paper paper1("Lincoln, A.", "C++ OOP", 1021, 2003); 
  Paper paper2("Bridge, C.", "Waltuh in 3D systems", 4026, 1992); 
  Paper paper3("Trinh, Q.", "Why OOP sucks", 7127, 2004, {&paper1, &paper2}, &paper1); 
  cout << "Quang Trinh's imaginary paper:\n"; 
  cout << paper3.getInfo(); 

  /**
   * Polymorphism: The ability to take many forms. 
   * - A derived class can act like a base class
   * - Different classes can be treated like a same class if they all follow an interface. 
   * ...Wait but
   * we know that interface in C++ is implemented using inheritance so
   * 1. Does it mean it's just case 1?
   * 2. Does C++ allow inheriting from many parents? 
  */
  vector<Document> Docs = {book1, paper1}; 
  for (auto doc : Docs) 
    cout << doc.getInfo();  // Uses Document::getInfo() 
  vector<Document*> PointersToDocs = {&book1, &paper1}; 
  for (auto ptr : PointersToDocs)
    cout << ptr->getInfo(); // Uses Paper::getInfo() / Book::getInfo()
}