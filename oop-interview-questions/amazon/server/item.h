#pragma once
#include <iostream>

class Item {
public:
  Item() {};
  Item(std::string name, std::string description, double price, int quantity);
  Item(const Item &oth);
  std::string getName() const;
  std::string getDescription() const;
  double getPrice() const;
  int getCount() const;
  void setCount(int newCount);
  void render();
private:
  std::string mName;
  std::string mDescription;
  double mPrice;
  int mCount;
};