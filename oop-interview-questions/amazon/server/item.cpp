#include "item.h"

Item::Item(std::string name, std::string description, double price, int quantity) :
  mName(name), mDescription(description), mPrice(price), mCount(quantity) {}

Item::Item(const Item &oth) : mName(oth.getName()), mDescription(oth.getDescription()), 
  mPrice(oth.getPrice()), mCount(oth.getCount()) {}

std::string Item::getName() const { return mName; }
std::string Item::getDescription() const { return mDescription; }
double Item::getPrice() const { return mPrice; }
int Item::getCount() const { return mCount; }

void Item::render()  {
  std::cout << mName << '\n';
  std::cout << "Price: " << mPrice << '\n';
  std::cout << ">> " << mDescription << '\n';
}