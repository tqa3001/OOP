#pragma once
#include <iostream>
#include <vector>
#include "payment.h"
#include "cart.h"

class User {
public:
  void addToCart(Item);
  void removeFromCart(Item);
private:
  std::string mName;
  std::string mPassword;
  std::vector<Payment> mHistory;
  Cart mCart;
};