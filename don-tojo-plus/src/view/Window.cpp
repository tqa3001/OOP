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
  std::cout << "About Page\n";
  WindowImpl::render();
}

ViewDishesWindow::ViewDishesWindow() {
  setDescription("Don Tojo Menu");
}

void ViewDishesWindow::render() {
  std::cout << "Take a look at Don Tojo's delicious menu!\n";
  WindowImpl::render();
}