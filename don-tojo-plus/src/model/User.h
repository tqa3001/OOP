#pragma once
#include <iostream>
#include <vector>
#include <set>
#include "./Food.h"

class User {
public:
  void updateInbox(std::string message);
  bool operator< (const User& oth) const {
    return username < oth.username;
  };
private:
  std::string username;
  std::vector<std::string> inbox;
  std::set<Food> PastDishes;
};