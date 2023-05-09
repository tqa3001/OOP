#include "cart.h"
#include <cassert>
#include <string>

double Cart::calculatePrice() {
  double result = 0;
  for (auto item : mBuyingList) {
    result += item.getCount() * item.getPrice();
  }
  return result;
}

void Cart::addToCart(Item item, int quantity) {
  for (int i = 0; i < (int)mBuyingList.size(); i++) {
    if (mBuyingList[i].getName() == item.getName()) {
      mBuyingList.erase(mBuyingList.begin() + 1);
      break;
    }
  }
  item.setCount(quantity);
  mBuyingList.push_back(item);
}

void Cart::removeFromCart(int position) {
  assert(position >= 0 && position < (int)mBuyingList.size());
  mBuyingList.erase(mBuyingList.begin() + position);
}

void Cart::renderCart() {
  for (int i = 0; i < (int)mBuyingList.size(); i++) {
    std::cout << "[" << i << "] - " << mBuyingList[i].getName();
    std::cout << " - " << std::to_string(mBuyingList[i].getCount()) << "pax - ";
    std::cout << "$" << std::to_string(mBuyingList[i].getPrice() * mBuyingList[i].getCount()) << '\n';
  }
  std::cout << "\nTotal: " << std::to_string(calculatePrice()) << '\n';
}