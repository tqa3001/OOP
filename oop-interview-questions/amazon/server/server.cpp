#include "server.h"
#include <cassert>

size_t Server::hash(std::string str) {
  return std::hash<std::string>{}(str);  /* Convenient but unsafe */
}

bool Server::findItem(std::string itemName, Item& result) {
  for (auto& item : mItems) {
    if (item.getName() == itemName) {
      result = Item(item);
      return true;
    }
  }
  return false;
}

bool Server::findUser(std::string userName, User& result) {
  for (auto& user : mUsers) {
    if (user.getUsername() == userName) {
      // result = User(user);
      result = user;
      return true;
    }
  }
  return false;
}

int Server::numberOfItems() { return mItems.size(); }

void Server::addItem(Item item) {
  mItems.push_back(item);
}

void Server::addUser(User user) {
  mUsers.push_back(user);
}

void Server::renderItems(int page) {
  int itemCount = mItems.size();
  assert(page * 5 < itemCount);
  std::cout << "Page " << page << "\n\n";
  for (int i = page * 5; i < std::min(itemCount, (page + 1) * 5); i++) {
    std::cout << "[" << i << "]: ";
    mItems[i].render();
    std::cout << "\n";
  }
}

Item Server::getItem(int position) {
  return mItems[position];
}