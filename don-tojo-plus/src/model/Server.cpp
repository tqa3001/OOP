#include "Server.h"
#include <string>

void MessageEmitter::notifySubscribers() {
  for (auto userPtr : subscribers) {
    userPtr.updateInbox(message);
  }
}

void MessageEmitter::subscribe(User &user) {
  subscribers.insert(user);
}

void MessageEmitter::unsubscribe(User &user) {
  subscribers.erase(user);
}

/* Listing strategy pattern implementation */

/* Server singleton class implementation */

void Server::getInstance() {
  if (serverPtr == nullptr) {
    serverPtr = new Server();
    serverPtr->startTime = clock() / CLOCKS_PER_SEC;
  }
  return serverPtr;
}

std::string Server::getStatus() {
  return "Server started running " + std::to_string(startTime) + "after program start";
}

void Server::registerNewUser(User user) {
  mUsers.insert(user);
}

void Server::removeUser(User user) {
  mUsers.erase(user);
}

void Server::addDish(Food dish) {
  menuDishes.insert(dish);
}

void Server::removeDish(Food dish) {
  menuDishes.erase(dish);
}

std::vector<Food> Server::getMenu(ListingStrategy strategy) {
  return strategy.apply(std::vector<Food>(menuDishes));
}