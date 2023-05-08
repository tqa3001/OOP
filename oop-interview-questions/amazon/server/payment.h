#pragma once
#include <iostream>
#include <vector>
#include "item.h"

class Payment {
public:
  double render();
private:
  std::vector<Item> mItems;
  double mPrice;
};