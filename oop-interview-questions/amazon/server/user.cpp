#include <vector>
#include <cassert>
#include "user.h"
#define MAX_CASH 4000.0

User::User(std::string username, size_t hashedPassword) :
  mUsername(username), mPassword(hashedPassword) { mCash = 0; }

User::User(const User &oth) : mUsername(oth.getUsername()), mPassword(oth.getPassword()),
  mCash(oth.getCash()), mHistory(oth.getHistory()), mCart(oth.getCart()) {}

double User::getCash() const { return mCash; }
std::string User::getUsername() const { return mUsername; }
size_t User::getPassword() const { return mPassword; }
std::vector<Payment> User::getHistory() const { return mHistory; }
Cart User::getCart() const { return mCart; }

void User::addToCart(Item item, int quantity) {
  assert(item.getCount() >= quantity && quantity > 0);
  mCart.addToCart(item, quantity);
}

bool User::addCash(double amount) {
  mCash = std::min(mCash + amount, MAX_CASH);
  return mCash >= MAX_CASH;
}

void User::setCash(double amount) { mCash = amount; }
void User::setUsername(std::string username) { mUsername = username; }
void User::setPassword(size_t hashedPassword) { mPassword = hashedPassword; }

Payment User::payWithInappCash() {  /* This does not handle empty payments */
  double price = mCart.calculatePrice();
  assert(price <= mCash);
  Payment newPayment(price, mCart.getCart());
  mCash -= price;
  mCart.reset();
  mHistory.push_back(newPayment);
  return newPayment;
}

Payment User::payWithCreditCard() {
  std::cout << "This might require a different receipt structure so maybe later\n";
  return Payment();
}

void User::viewHistory() {
  std::cout << "Your shopping history: \n";
  for (auto payment : mHistory) {
    payment.render();
  }
  std::cout << '\n';
}