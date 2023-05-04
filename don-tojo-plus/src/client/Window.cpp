#include "Window.h"

WindowMenu::WindowMenu() {}

void WindowMenu::add(char buttonPressed, Window &windowPtr) {
  M[buttonPressed] = windowPtr;
}

void WindowMenu::print() {
  for (auto T : M) {
    std::cout << "[" << T.first << "] - " << T.second.getDescription() << '\n';
  }
  std::cout << "[x] - Return/Exit\n";
}

int WindowMenu::run() {
  char input; 
  std::cin >> input;
  if (input == 'x')
    return 1; 
  auto pt = M.find(input); 
  if (pt == M.end())
    return -1;
  (*pt).second.run(); 
  return 0; 
}

AboutWindow::AboutWindow() {
 setDescription("About");
}

int AboutWindow::run() {
  std::cout << "About\n";
  return 0;
}

ViewDishesWindow::ViewDishesWindow() {
  setDescription("Don Tojo Menu");
}

int ViewDishesWindow::run() {
  std::cout << "balls\n";
  return 0;
}