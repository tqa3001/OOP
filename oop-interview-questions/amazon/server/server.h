#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "./user.h"

/* Currently very inefficient, lots of room for optimization */
class Server {
public:
  Server() {}
  size_t hash(std::string str);
  bool findItem(std::string itemName, Item& result);
  bool findUser(std::string userName, User*& result);
  int numberOfItems();
  void addItem(Item item);
  void addUser(User user);
  void renderItems(int page);
  void process(Payment payment);
  Item getItem(int position);
  std::vector<User> mUsers;
private:
  std::vector<Item> mItems;
  std::unordered_map<std::string, int> mUserHashMap;
  std::unordered_map<std::string, int> mItemHashMap;
};