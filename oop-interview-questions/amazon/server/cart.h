#pragma once
#include <iostream>
#include <vector>
#include <set>
#include "item.h"

class Cart {
public:
  void reset();
  double calculatePrice();
  int numberOfItems();
  void addToCart(Item item, int quantity);
  void removeFromCart(int position);
  std::vector<Item> getCart();
  std::vector<Item> renderCart();
private:
  std::vector<Item> mBuyingList;
};