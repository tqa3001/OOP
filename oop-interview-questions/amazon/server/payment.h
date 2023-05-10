#pragma once
#include "item.h"
#include <iostream>
#include <vector>

class Payment {
public:
  void timestamp();
  Payment() { timestamp(); }
  Payment(double price, std::vector<Item> items) :
    mPrice(price), mItems(items) { timestamp(); }
  void render();
  std::vector<Item> getItems();
private:
  std::string mTime;
  double mPrice;
  std::vector<Item> mItems;
};