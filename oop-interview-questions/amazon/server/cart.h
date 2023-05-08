#pragma once
#include <iostream>
#include <vector>
#include "item.h"

class Cart {
public:
  double calculatePrice();
  void addToCart(Item);
  void removeFromCart(Item);
private:
  std::vector<Item> mBuyingList;
};