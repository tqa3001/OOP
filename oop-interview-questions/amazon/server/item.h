#pragma once
#include <iostream>

class Item {
public:
  void render();
private:
  int mCount;
  double mPrice;
  std::string mName;
  std::string mDescription;
};