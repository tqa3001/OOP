#include <iostream>
#include <string>

class Window {
public:
  virtual void run() = 0; 
  std::string getDescription() { return description; }
private:
  std::string description; 
};