#include <vector>
#include "user.h"

User::User(const User &oth) : mUsername(oth.getUsername()), mPassword(oth.getPassword()),
  mHistory(oth.getHistory()), mCart(oth.getCart()) {}

std::string User::getUsername() const { return mUsername; }
size_t User::getPassword() const { return mPassword; }
std::vector<Payment> User::getHistory() const { return mHistory; }
Cart User::getCart() const { return mCart; }

void User::setUsername(std::string username) { mUsername = username; }
void User::setPassword(size_t hashedPassword) { mPassword = hashedPassword; }