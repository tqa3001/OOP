#include "Server.h"
#include <string>
#include <algorithm>

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

std::string Server::getStatus() {
  return "Server is running...\n";
  // return "Server started running " + std::to_string(startTime) + "after program start";
}

void Server::registerNewUser(User user) {
  mUsers.insert(user);
}

void Server::removeUser(User user) {
  mUsers.erase(user);
}

void Server::addDish(Food dish) {
  for (auto tmp : menuDishes) {
    Food existingDish = tmp.first;
    if (dish == existingDish) {
      return;
    }
  }
  menuDishes.push_back({dish, users_t()});
}

void Server::removeDish(Food dish) {
  for (int i = 0; i < (int)menuDishes.size(); i++) {
    if (menuDishes[i].first == dish) {
      menuDishes.erase(menuDishes.begin() + i);
      return;
    }
  }
}

int Server::toggleVote(Food dish, User user) {
  for (auto& tmp : menuDishes) {
    if (tmp.first == dish) {
      if (tmp.second.find(user) != tmp.second.end()) {
        tmp.second.erase(user);
        return 0;
      } else {
        tmp.second.insert(user);
        return 1;
      }
    }
  }
}

std::vector<Food> Server::getMenu(ListingStrategy &strategy) {
  std::vector<Food> dishes;
  for (auto &T : menuDishes) {
    dishes.push_back(T.first);  /* if i'm correct, T is lvalue -> creates new copy */
  }
  return strategy.apply(dishes);
}

std::vector<Food> AlphebeticalListingStrategy::apply(std::vector<Food> &dishes) {
  std::vector<Food> ret(dishes);
  std::sort(ret.begin(), ret.end(), [](Food &a, Food &b) { 
    return a.getName() < b.getName(); 
  });
  return ret;
}

std::vector<Food> ReverseAlphebeticalListingStrategy::apply(std::vector<Food> &dishes) {
  std::vector<Food> ret(dishes);
  std::sort(ret.begin(), ret.end(), [](Food &a, Food &b) { 
    return a.getName() < b.getName(); 
  });
  return ret;
}