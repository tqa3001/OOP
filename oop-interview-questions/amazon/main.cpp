#include "./server/server.h"
#include "./controller/controller.h"
#include <iostream>

signed main() {
  Server server;
  Controller controller(server);
  controller.welcomeBoard();
}