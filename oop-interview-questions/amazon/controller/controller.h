#include "../server/server.h"
#include "../server/user.h"
#include <iostream>

class Controller {
public:
  Controller(Server& server);
  std::string getInput();
  void init();
  void login();
  void signup();
  void renderMenu();
  void run();
  void listAllItems(User& mUser);
  void viewItem(Item viewItem, User& mUser);
private:
  User* mUserPtr;
  Server mServer;
};