#include "Window.h"

WindowImpl::WindowImpl() {}

void WindowImpl::addWindow(std::string input, Window* windowPtr) {
  mNext[input] = windowPtr;
}

Window* WindowImpl::nextWindow(std::string input) {
  auto pt = mNext.find(input); 
  if (pt == mNext.end()) {
    return nullptr;
  }
  return (*pt).second;
}

void WindowImpl::render() {
  std::cout << "\nOptions:\n";
  for (auto zipped : mNext) {
    std::string option = zipped.first;
    Window* window = zipped.second;
    std::cout << "[" << option << "] - " << window->getDescription() << '\n';
  }
  std::cout << "[x] - Back/Exit\n";
  std::cout << "\nEnter: ";
}

StartingWindow::StartingWindow() {
  addWindow("1", &dishes);
  addWindow("2", &about);
}

void StartingWindow::render() {
  std::cout << "=========================================\n";
  std::cout << "Welcome to the Don Tojo fanclub!\n";
  WindowImpl::render();
}

AboutWindow::AboutWindow() {
  setDescription("About");
}

void AboutWindow::render() {
  std::cout << "About Page\n\n";
  std::string para =   
    "Hello! If you are a Unimelb Parkville student, there's a good chance that you have came across\n"
    "the famous Japanese restaurant Don Tojo at 164 Cardigan Street, Carlton.\n"
    "Don and Udon dishes here are not only delicious but also very affordable,\n"
    "making it the perfect lunch and dinner option for us dirt poor students with crippling tuition debt!\n\n"
    "One special feature of Don Tojo is that the entire menu with ~30 dishes can be \n"
    "formed from a small set of ingredients, which inevitably leads to these questions:\n"
    "What's the maximum number of Don/Udon dishes can Don Tojo make?\n"
    "Among those dishes, how many of them are culinary masterpieces?\n"
    "And how many of them are messes of ingredients that don't match?\n\n"
    "This small program is the first step towards tackling this million-dollar problem.";
  std::cout << para << '\n';
  WindowImpl::render();
}

ViewDishesWindow::ViewDishesWindow() {
  setDescription("Don Tojo Menu");
}

void ViewDishesWindow::render() {
  std::cout << "Take a look at Don Tojo's delicious menu!\n";
  for (auto dish : menu) {
    std::cout << dish.getName() << '\n';
  } // todo: FoodWindow
  WindowImpl::render();
}
