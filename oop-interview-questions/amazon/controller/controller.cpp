#include "controller.h"
#include <iostream>
#include <string>
#include <functional>

Controller::Controller(Server &server) {
  mServer = server;
}

std::string Controller::getInput() {
  std::string ret;
  std::getline(std::cin, ret);
  system("cls");
  return ret;
}

size_t Controller::hash(std::string str) {
  return std::hash<std::string>{}(str);  /* Convenient but unsafe */
}

void Controller::init() {
  system("cls");
  while (true) {
    std::cout << "Welcome to Amazon Ripoff! Please login or signup to continue.\n";
    std::cout << "Press a number ([1] for login, [2] for signup, [x] for exit): ";
    std::string input = getInput();
    if (input == "1") {
      login();
    } else if (input == "2") {
      signup();
    } else if (input == "x") {
      std::cout << "Goodbye!\n";
      break;
    }
  }
}

void Controller::login() {
  std::cout << "Enter your username: ";
  User user; 
  if (!mServer.findUser(getInput(), user)) {
    std::cout << "Username not found. Please try again.\n";
  } else {
    std::cout << "User is found. Please enter your password: \n";
    size_t hashed = hash(getInput());
    if (user.getPassword() != hashed) {
      std::cout << "Incorrect password.\n";
    } else {
      std::cout << "Login successful!\n\n";
      mUser = user;
      run();
    }
  }
}

void Controller::signup() {
  std::cout << "Choose a new username: ";
  std::string username = getInput();
  User user, duplicate;
  user.setUsername(username);
  if (mServer.findUser(username, duplicate)) {
    std::cout << "Username already exists!\n";
  } else {
    std::cout << "Choose a password: ";
    size_t hashedPassword = hash(getInput());
    user.setPassword(hashedPassword);
    mServer.addUser(user);
    std::cout << "New user created! Please login.\n";
  }
}

void Controller::renderMenu() {
  std::cout << "Welcome to Amazon ripoff!\n\n";
  std::cout <<
    "[0] - view items\n"
    "[1] - view cart\n"
    "[2] - add item to cart\n"
    "[3] - remove item from cart\n"
    "[4] - make payment\n"
    "[5] - view history\n"
    "[6] - log out\n";
  std::cout << "Enter a number: ";
}

void Controller::run() {
  while (true) {
    std::cout << "Logged in as " << mUser.getUsername() << '\n';
    renderMenu();
    std::string input = getInput();
    std::cout << "Entered: " << input << '\n'; 
    if (input == "x") {
      break;
    }
    if (input == "0") {
      continue;
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
    if (input == "6") {
      mUser = User();
      std::cout << "Logout successful\n";
      break;
    }
    std::cout << "Invalid input, please type again\n";
  }
}