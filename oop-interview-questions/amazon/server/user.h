#pragma once
#include <iostream>
#include <vector>
#include "payment.h"
#include "cart.h"

class User {
public:
  User() {}
  User(const User &oth);
  std::string getUsername() const;  /* Make this a const_ptr*/
  size_t getPassword() const;
  std::vector<Payment> getHistory() const;
  Cart getCart() const;
  void setUsername(std::string username);
  void setPassword(size_t hashedPassword);
private:
  std::string mUsername;
  size_t mPassword;
  std::vector<Payment> mHistory;
  Cart mCart;
};