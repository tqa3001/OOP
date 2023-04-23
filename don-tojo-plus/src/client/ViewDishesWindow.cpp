#include <iostream>
#include <string>
#include "./Window.cpp"

class ViewDishesWindow : public Window {
public:
  void runx() {
    std::cout << "balls";
  }
private: 
  std::string description;
};