#include <iostream>
#include "./view/Window.h"
#include "./model/Server.h"
#include "./controller/Controller.h"
using std::cout;

void run() {
  cout << server.getInstance();
  cout << "=========================================\n";
  cout << "Welcome to the Don Tojo fanclub! Press:\n\n";
  WindowMenu menu;
  ViewDishesWindow dishes;
  AboutWindow about;
  menu.add('1', dishes);
  menu.add('2', about);
  menu.print();
  menu.run();
}

main() {
  run(); 
  return 0; 
}