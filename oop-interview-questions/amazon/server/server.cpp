#include "server.h"
#include <cassert>
#include <unordered_map>

size_t Server::hash(std::string str) {
  return std::hash<std::string>{}(str);  /* Convenient but unsafe */
}

bool Server::findUser(std::string userName, User*& result) {
  auto position = mUserHashMap.find(userName);
  if (position != mUserHashMap.end()) {
    result = &mUsers[(*position).second];
    return true;
  }
  return false;
}

bool Server::findItem(std::string itemName, Item& result) {
  auto position = mItemHashMap.find(itemName);
  if (position != mItemHashMap.end()) {
    result = mItems[(*position).second];
    return true;
  }
  return false;
}

int Server::numberOfItems() { return mItems.size(); }

void Server::addItem(Item item) {
  assert(mItemHashMap.find(item.getName()) == mItemHashMap.end());
  mItemHashMap[item.getName()] = mItems.size();  /* removing items would be a pain */
  mItems.push_back(item);
}

void Server::addUser(User user) {
  assert(mUserHashMap.find(user.getUsername()) == mUserHashMap.end());
  mUserHashMap[user.getUsername()] = mUsers.size();
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

void Server::process(Payment payment) {
  std::vector<Item> itemList = payment.getItems();
  for (auto paymentItem : itemList) {
    int position = mItemHashMap[paymentItem.getName()];
    int oldCount = mItems[position].getCount();
    mItems[position].setCount(oldCount - paymentItem.getCount());
  }
}

Item Server::getItem(int position) {
  return mItems[position];
}