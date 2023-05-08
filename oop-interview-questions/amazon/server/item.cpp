#include "item.h"

void Item::render()  {
  std::cout << name << '\n';
  std::cout << "Price: " << price << '\n';
  std::cout << ">> " << description << '\n';
}