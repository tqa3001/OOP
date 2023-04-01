/* Hello world for unit testing */
#include <iostream>
using namespace std;

class Message {
  string type, text; 
public: 
  Message(string type, string text) : type(type), text(text) {}
  string msg() { return type + ": " + text; }
}; 

int main() {
  Message T("Init", "Hello World!"); 
  cout << T.msg(); 
}