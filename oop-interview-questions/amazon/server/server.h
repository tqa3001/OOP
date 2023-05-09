#pragma once
#include <iostream>
#include <vector>
#include "./user.h"

class Server {
public:
  Server() {}
  size_t hash(std::string str);
  bool findItem(std::string itemName, Item& result);
  bool findUser(std::string userName, User& result);
  int numberOfItems();
  void addItem(Item item);
  void addUser(User user);
  void renderItems(int page);
  Item getItem(int position);
private:
  std::vector<User> mUsers;
  std::vector<Item> mItems;
};