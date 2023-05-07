#include "Controller.h"
#include "../model/Server.h"
#include <string>

Controller::Controller(Window *firstWindow) {
  mWindowStack.push_back(firstWindow);
}

std::string Controller::getUserInput() {
  std::string ret;
  std::getline(std::cin, ret);
  std::cout << '\n';
  system("cls");
  // something something with std::cin.ignore() so be careful
  return ret;
}

void Controller::run() {
  std::string input;
  while (true) {
    Window* currentWindow = mWindowStack.back();
    prepWindow(currentWindow);
    currentWindow->render();
    input = getUserInput();
    if (input == "x") {
      mWindowStack.pop_back();
      if (mWindowStack.empty()) {
        break;
      }
    } else {
      Window* nxt = currentWindow->nextWindow(input);
      if (nxt == nullptr) {
        std::cout << "Invalid input! Please re-enter.\n\n";
      } else {
        mWindowStack.push_back(nxt);
      }
    }
  }
}

void Controller::prepWindow(Window* window) {
  std::string windowDescription = window->getDescription();
  if (windowDescription == "About") {
    return;
  }
  
  if (windowDescription == "Don Tojo Menu" ) {
    ViewDishesWindow* menuWindow = dynamic_cast<ViewDishesWindow*>(window);
    while (true) {
      std::cout << "Select display order: (1 - sorted, 2 - reverse sorted) ";
      std::string input = getUserInput();
      if (input == "1") {
        AlphebeticalListingStrategy strategy;
        menuWindow->setMenu(Server::getInstance().getMenu(strategy));
        std::cout << "bruh!\n";
        break;
      } 
      if (input == "2") {
        ReverseAlphebeticalListingStrategy strategy;
        menuWindow->setMenu(Server::getInstance().getMenu(strategy));
        break;
      }
      std::cout << "Invalid input! Please re-enter: ";
    }
    return;
  }

}