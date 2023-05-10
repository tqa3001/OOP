#include "../server/server.h"
#include "../server/user.h"
#include <iostream>

class Controller {
public:
  Controller(Server& server, User &guest);
  std::string getInput();
  void init();
  void login();
  void signup();
  void renderMenu();
  void run();
  void listAllItems();
  void viewItem(Item viewItem);
private:
  User &mUser;
  Server mServer;
};