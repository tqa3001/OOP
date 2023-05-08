#include "server.h"

Server::Server() {
  std::cout << "server loaded\n";
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
      result = User(user);
      return true;
    }
  }
  return false;
}

void Server::addItem(Item &item) {
  mItems.push_back(item);
}

void Server::addUser(User &user) {
  mUsers.push_back(user);
}