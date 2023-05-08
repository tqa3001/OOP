#pragma once
#include <iostream>
#include <vector>
#include "./user.h"

class Server {
public:
  Server();
  bool findItem(std::string itemName, Item& result);
  bool findUser(std::string userName, User& result);
  void addItem(Item &item);
  void addUser(User &user);
private:
  std::vector<User> mUsers;
  std::vector<Item> mItems;
};