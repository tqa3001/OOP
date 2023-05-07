#include "Controller.h"
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