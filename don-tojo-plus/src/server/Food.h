#include <iostream>

class Food {
public:
  Food();
  std::string getName() { return name; }
  virtual std::string getDescription() = 0;
private:
  std::string name;
  std::string rice, noodle;
  std::string meat;
  std::string vegetable;
  std::string soup;
};