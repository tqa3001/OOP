#include "User.h"

void User::updateInbox(std::string message) {
  inbox.push_back(message);
}