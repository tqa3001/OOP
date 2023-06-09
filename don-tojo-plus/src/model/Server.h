#pragma once
#include <vector>
#include <set>
#include <time.h>
#include "User.h"
#include "Food.h"
typedef std::set<User> users_t;  /* Note: set<T&> is compile error, you can't store refs */

class MessageEmitter {
public:
  void setMessage(std::string msg) {
    message = msg;
  }
  void notifySubscribers();
  void subscribe(User&);
  void unsubscribe(User&);
private:
  std::string message;
  users_t subscribers;
};

class ListingStrategy {
public:
  virtual std::vector<Food> apply(std::vector<Food> &dishes) = 0;
};

class AlphebeticalListingStrategy : public ListingStrategy {
public:
  AlphebeticalListingStrategy() {};
  std::vector<Food> apply(std::vector<Food> &dishes);
};

class ReverseAlphebeticalListingStrategy : public ListingStrategy {
public:
  ReverseAlphebeticalListingStrategy() {};
  std::vector<Food> apply(std::vector<Food> &dishes);
};

class Server {
public:
  /* Enforce Server to be a singleton */
  /* Note: This imple is NOT thread safe*/
  Server(Server &server) = delete;    /* Avoid cloning */
  void operator= (Server &server) = delete;     /* Avoid implicit copy assignment */

  /* Safer method for getting the instance of Server */
  static Server& getInstance() {
    static Server instance;  /* lazy initiated and correctly destroyed */
    if (!instance.isLoaded) {
      instance.startTime = clock() / CLOCKS_PER_SEC;
      instance.isLoaded = true;
    }
    return instance;
  }

  /* Methods */
  std::string getStatus();
  void registerNewUser(User);
  void removeUser(User);
  void addDishes(std::vector<Food> &dishes);
  void removeDish(Food);
  int toggleVote(Food, User);
  std::vector<Food> getMenu(ListingStrategy &strategy);

private:
  Server() : isLoaded(false) {
    std::vector<Food> confirmedMenu = {Food("Sukiyaki Don"), Food("Teriyaki Don")};
    addDishes(confirmedMenu);
  };
  bool isLoaded;
  double startTime;
  users_t mUsers;
  std::vector<std::pair<Food, users_t> > menuDishes;
  MessageEmitter messageEmitter;
};

/* Static variables are like global variables that are in the namespace of a class, they need
  to be defined somewhere. */
// double Server::startTime;  