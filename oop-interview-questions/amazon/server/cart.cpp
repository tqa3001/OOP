#include "cart.h"
#include <cassert>
#include <string>

void Cart::reset() { mBuyingList.clear(); }

double Cart::calculatePrice() {
  double result = 0;
  for (auto item : mBuyingList) {
    result += item.getCount() * item.getPrice();
  }
  return result;
}

int Cart::numberOfItems() { return mBuyingList.size(); }

void Cart::addToCart(Item item, int quantity) {
  bool foundInCart = false;
  for (int i = 0; i < (int)mBuyingList.size(); i++) {
    if (mBuyingList[i].getName() == item.getName()) {
      mBuyingList[i].setCount(quantity);
      foundInCart = true;
      break;
    }
  }
  if (!foundInCart) {
    item.setCount(quantity);
    mBuyingList.push_back(item);
  }
}

void Cart::removeFromCart(int position) {
  assert(position >= 0 && position < (int)mBuyingList.size());
  mBuyingList.erase(mBuyingList.begin() + position);
}

std::vector<Item> Cart::renderCart() {
  int cnt = numberOfItems();
  for (int i = 0; i < cnt; i++) {
    std::cout << "[" << i << "] - " << mBuyingList[i].getName();
    std::cout << " - " << std::to_string(mBuyingList[i].getCount()) << "pax - ";
    std::cout << "$" << std::to_string(mBuyingList[i].getPrice() * mBuyingList[i].getCount()) << '\n';
  }
  std::cout << "\nTotal: " << std::to_string(calculatePrice()) << '\n';
  return mBuyingList;
}

std::vector<Item> Cart::getCart() { return mBuyingList; }