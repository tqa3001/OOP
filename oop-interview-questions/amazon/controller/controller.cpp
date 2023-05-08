#include "controller.h"
#include <iostream>
#include <string>

std::string Controller::getInput() {
  std::string ret;
  std::getline(std::cin, ret);
  std::cin.ignore();
  system("cls");
  return ret;
}

void Controller::renderMenu() {
  std::cout << "Welcome to Amazon ripoff\n\n";
  std::cout <<
    "[0] - view items\n"
    "[1] - view cart\n"
    "[2] - add item to cart\n";
    "[3] - remove item from cart\n"
    "[4] - make payment\n"
    "[5] - view history";
}

void Controller::run() {
  while (true) {
    renderMenu();
    std::string input = getInput();
    if (input == "x") {
      break;
    }
    if (input == "1") {
      continue;
    }
    if (input == "2") {
      continue;
    }
    if (input == "3") {
      continue;
    }
    if (input == "4") {
      continue;
    }
    if (input == "5") {
      continue;
    }
    std::cout << "Invalid input, please type again\n";
  }
}