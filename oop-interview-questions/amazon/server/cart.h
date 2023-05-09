#pragma once
#include <iostream>
#include <vector>
#include <set>
#include "item.h"

class Cart {
public:
  double calculatePrice();
  void addToCart(Item item, int quantity);
  void removeFromCart(int position);
  void renderCart();
private:
  std::vector<Item> mBuyingList;
};