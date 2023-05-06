#include <iostream>
#include <vector>
#include <set>
#include "./Food.h"

class User {
public:
  virtual void updateInbox() = 0;
private:
  std::string username;
  std::vector<std::string> inbox;
  std::set<Food> PastDishes;
};