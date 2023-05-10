#pragma once
#include <iostream>
#include <vector>
#include "payment.h"
#include "cart.h"

class User {
public:
  /* constructors */
  User() {}
  User(std::string username, size_t hashedPassword);
  User(const User &oth);

  /* getters */
  double getCash() const;
  std::string getUsername() const;  /* const methods are needed for the copy constructor */
  size_t getPassword() const;
  std::vector<Payment> getHistory() const;
  Cart getCart() const;
  void viewHistory();

  /* setters and update methods */
  bool addCash(double amount);
  void setCash(double amount);
  void addToCart(Item item, int quantity);
  void setUsername(std::string username);
  void setPassword(size_t hashedPassword);
  Payment payWithInappCash();
  Payment payWithCreditCard();

private:
  double mCash;
  std::string mUsername;
  size_t mPassword;
  std::vector<Payment> mHistory;
  Cart mCart;
};