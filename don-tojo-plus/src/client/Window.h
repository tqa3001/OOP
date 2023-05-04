#pragma once
#include <iostream>
#include <unordered_map>

class Window {
public:
  virtual int run() = 0; 
  void setDescription(std::string str) { description = str; }
  std::string getDescription() { return description; }
private:
  std::string description; 
};

class WindowMenu : public Window {
public:
  WindowMenu();
  void add(char buttonPressed, Window *windowPtr);
  void print();
  int run();
private:
  std::unordered_map<char, Window*> M;
};

class AboutWindow : public Window {
public:
  AboutWindow();
  int run();
};

class ViewDishesWindow : public Window {
public:
  ViewDishesWindow();
  int run();
};