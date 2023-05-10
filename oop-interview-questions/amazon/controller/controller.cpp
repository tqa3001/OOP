#include "controller.h"
#include <iostream>
#include <string>
#include <cassert>

Controller::Controller(Server &server, User &guest) : mUser(guest) {
  mServer = server;
  /* Add items to database */
  mServer.addItem(Item("Broom", "A based broom that is also very cheap I think", 5.6, 100));
  mServer.addItem(Item("Kmart Dog", "Epic chihuahua for your mom!", 53, 20));
  mServer.addItem(Item("College Degree", 
    "From Goofstercum University.\n Class of 2025. Proudly given by Endrew Tute", 6900.545, 14));
  mServer.addItem(Item("Kmart Cat", "El gato! Imported from Ohio ", 36, 22));
  mServer.addItem(Item("Tim Tam", "Hood classic", 5.2, 200));
  mServer.addItem(Item("Antidepressants", "Mood classic", 24.5, 70));
  mServer.addItem(Item("KFC Chicken Combo", "Foot classic", 15.7, 50));
  /* Add users to database */
  // mServer.addUser(User("quanganh", mServer.hash("123")));
  mServer.addUser(User("a", mServer.hash("a")));
}

std::string Controller::getInput() {
  std::string ret;
  std::getline(std::cin, ret);
  system("cls");
  return ret;
}

void Controller::init() {
  system("cls");
  while (true) {
    std::cout << "Welcome to Amazon Ripoff! Please login or signup to continue.\n";
    std::cout << "Select option: [1] for login, [2] for signup, [x] for exit\n";
    std::string input = getInput();
    std::cout << "bruh! carts!\n";
    for (auto& user : mServer.mUsers) {
      std::cout << user.getUsername() << '\n';
      user.getCart().renderCart();
      std::cout << '\n';
    }
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
  User* userPtr;
  if (!mServer.findUser(getInput(), userPtr)) {
    std::cout << "Username not found. Please try again.\n";
  } else {
    std::cout << "User is found. Please enter your password: \n";
    size_t hashed = mServer.hash(getInput());
    if (userPtr->getPassword() != hashed) {
      std::cout << "Incorrect password.\n";
    } else {
      std::cout << "Login successful!\n\n";
      mUser = *userPtr;
      run();
    }
  }
}

void Controller::signup() {
  std::cout << "Choose a new username: ";
  std::string username = getInput();
  User user;
  User* duplicate;
  user.setUsername(username);
  if (mServer.findUser(username, duplicate)) {
    std::cout << "Username already exists!\n";
  } else {
    std::cout << "Choose a password: ";
    size_t hashedPassword = mServer.hash(getInput());
    user.setPassword(hashedPassword);
    mServer.addUser(user);
    std::cout << "New user created! Please login.\n";
  }
}

void Controller::renderMenu() {
  std::cout << "\n*** Welcome to Amazon ripoff! ***\n\n";
  std::cout <<
    "[0] - view and add items to cart\n"
    "[1] - edit cart and pay\n"
    "[2] - view history\n"
    "[3] - top up inapp cash\n"
    "[x] - log out\n";
  std::cout << "\nSelect a number: ";
}

/* Too long, needs refactoring 
  Other issues:
  - Too many conditionals 
  - Inconsistent, borderline ugly error handling 
  - Is code self-explanatory?
  - string for int, why? */
void Controller::run() {
  while (true) {
    std::cout << "Logged in as " << mUser.getUsername() << '\n';
    std::cout << "In-app cash: $" << mUser.getCash() << '\n';
    renderMenu();
    std::string input = getInput();
    std::cout << "Entered: " << input << '\n'; 
    if (input == "x") {
      break;
    }
    if (input == "0") {
      listAllItems();
    }
    if (input == "1") {
      std::cout << "\nYour cart currently contains: \n";
      std::vector<Item> cartItem = mUser.getCart().renderCart();
      std::cout << "\n[p] - Payment | [item number] - Edit item | [x] - Back\n";
      std::cout << "Select option: ";
      std::string input = getInput();
      if (input == "p") {
        std::cout << "Select payment option: [1] - With in-app cash | [2] - With a credit card\n";
        std::cout << "Enter: ";
        input = getInput();
        if (input == "1") {
          if (mUser.getCash() >= mUser.getCart().calculatePrice()) {
            Payment newPayment = mUser.payWithInappCash();
            mServer.process(newPayment);
            std::cout << "Successfully made the payment. Here is your receipt:\n";
            newPayment.render();
          } else {
            std::cout << "Not enough in-app cash. You can load more cash from the menu.\n";
          }
        } else if (input == "2") {
          mUser.payWithCreditCard();
        }
      } else if (input != "x") {
        try {
          int itemPos = std::stoi(input);
          if (itemPos >= 0 && itemPos < mUser.getCart().numberOfItems()) {
            Item shopItem;
            assert(mServer.findItem(cartItem[itemPos].getName(), shopItem));
            viewItem(shopItem);
          } else {
            throw std::exception();
          }
        } catch (const std::exception &e) {
          /* Maybe std::cerr is better (output to error stream) */
          /* Builtin exception classes: https://en.cppreference.com/w/cpp/error/exception */
          std::cout << "Invalid input: " << e.what() << "\n\n";
        }
      }
      continue;
    }
    if (input == "2") {
      mUser.viewHistory();
      continue;
    }
    if (input == "3") {
      bool maxCashReached = mUser.addCash(300);
      std::cout << "You now have " << mUser.getCash() << " after adding $300\n";
      if (maxCashReached) {
        std::cout << "Maximum cash amount reached.\n";
      }
      std::cout << '\n';
      continue;
    }
    if (input == "x") {  /* Clear cart? */
      std::cout << "Logout successful\n";
      break;
    }
    std::cout << "Invalid input, please type again\n";
  }
}

/* A viewer class or something -> for history as well. */
void Controller::listAllItems() {
  int page = 0;
  while (true) {
    std::cout << 
      "Showing 5 items at a time.\n"
      "To navigate: [a] - previous page, [s] - next page\n"
      "To add to cart, first enter item number.\n"
      "To go back, enter [x].\n\n";
    mServer.renderItems(page);
    std::string input = getInput();
    if (input == "a") {
      page = std::max(0, page - 1);
    } else if (input == "s") {
      int maxPageCount = (mServer.numberOfItems() + 4) / 5;
      page = std::min(maxPageCount - 1, page + 1);
    } else if (input == "x") {
      break;
    } else {
      try {
        int position = std::stoi(input);
        if (position >= 0 && position < mServer.numberOfItems()) {
          Item item = mServer.getItem(position); 
          viewItem(item);
        } else {
          throw std::exception();
        }
      } catch (const std::exception &e) {
        /* Maybe std::cerr is better (output to error stream) */
        /* Builtin exception classes: https://en.cppreference.com/w/cpp/error/exception */
        std::cout << "Invalid input: " << e.what() << "\n\n";
      }
    }
  }
}

void Controller::viewItem(Item item) {
  std::cout << "There are " + std::to_string(item.getCount()) + " <" + 
    item.getName() + "> left.\n";
  std::cout << 
    "How many of this item do you want to add to cart?\n"
    "This will replace your current quantity for this item.\n"
    "To remove this item from cart, choose 0.\n";
  std::cout << "\nEnter quantity: ";
  int quantity = std::stoi(getInput());
  if (quantity > 0 && quantity <= item.getCount()) {
    mUser.addToCart(item, quantity);
    std::cout << "Added " << std::to_string(quantity) << " <" + item.getName() + "> to cart.\n\n";
  } else {
    std::cout << "Invalid quantity!\n";
  }
}