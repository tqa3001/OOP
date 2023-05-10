#include "./server/server.h"
#include "./controller/controller.h"
#include <iostream>

signed main() {
  User guest;
  Server server;
  Controller controller(server, guest);
  controller.init();
}