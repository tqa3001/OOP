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
  void run();
  void renderMenu();
private:
  User mUser;
  Server mServer;
};