#pragma once;
#include <iostream>
#include <vector>
#include "item.h"

class Cart {
public:
  double calculatePrice();
private:
  std::vector<Item> mBuyingList;
};