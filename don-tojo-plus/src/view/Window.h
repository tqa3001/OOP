#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "../model/Food.h"

class Window {
public:
  void setDescription(std::string str) { mDescription = str; }
  std::string getDescription() { return mDescription; }
  virtual void addWindow(std::string input, Window* windowPtr) = 0;
  virtual Window* nextWindow(std::string input) = 0;
  virtual void render() = 0;
protected:
  std::string mDescription; 
  std::unordered_map<std::string, Window*> mNext;
};

class WindowImpl : public Window {
public:
  WindowImpl();
  void addWindow(std::string input, Window* windowPtr);
  Window* nextWindow(std::string input);
  virtual void render();
};

class AboutWindow : public WindowImpl {
public:
  AboutWindow();
  void render();
};

class ViewDishesWindow : public WindowImpl {
public:
  ViewDishesWindow();
  void setMenu(std::vector<Food> inputMenu) { menu = inputMenu; }
  void render();
private:
  std::vector<Food> menu;
};

class StartingWindow : public WindowImpl {
public:
  StartingWindow();
  void render();
private:
  AboutWindow about;
  ViewDishesWindow dishes;
};
