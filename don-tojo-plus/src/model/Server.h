#include <set>
#include <unordered_map>
#include "User.h"
#include "Food.h"

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
  std::set<User&> subscribers;
};

class ListingStrategy {
  virtual void apply(std::vector<Food> &dishes) = 0;
};

class AlphebeticalListingStrategy : public ListingStrategy {};

class Server {
public:
  /* Enforce Server to be a singleton */
  /* Note: This imple is NOT thread safe*/
  Server(Server &server) = delete;    /* Avoid cloning */
  void operator= (Server &server) = delete;     /* Avoid implicit copy assignment */

  /* Safer method for getting the instance of Server */
  static Server& getInstance() {
    static Server instance;  /* lazy initiated and correctly destroyed */
    return instance;
  }

  /* Methods */
  std::string getStatus();
  void registerNewUser(User);
  void removeUser(User);
  void addDish(Food);
  void removeDish(Food);
  std::vector<Food> getMenu(ListingStrategy &strategy);

private:
  Server() {};
  double startTime;
  std::vector<User> mUsers;
  std::unordered_map<Food, int> requestCount; 
  std::set<Food> menuDishes;
  MessageEmitter messageEmitter;
} server;