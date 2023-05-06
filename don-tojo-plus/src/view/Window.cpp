#include "Window.h"

WindowImpl::WindowImpl() {}

void WindowImpl::addWindow(char input, Window* windowPtr) {
  mNext[input] = windowPtr;
}

Window* WindowImpl::nextWindow(char input) {
  auto pt = mNext.find(input); 
  if (pt == mNext.end())
    nullptr;
  return (*pt).second;
}

void WindowImpl::render() {
  for (auto zipped : mNext) {
    char option = zipped.first;
    Window* window = zipped.second;
    std::cout << "[" << option << "] - " << window->getDescription() << '\n';
  }
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