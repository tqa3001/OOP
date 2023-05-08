#include "../server/server.h"
#include "../server/user.h"
#include <iostream>

class Controller {
public:
  Controller(Server& server);
  std::string getInput();
  std::string hash(std::string);
  void login();
  void run();
  void renderMenu();
private:
  User mUser;
  Server mServer;
};