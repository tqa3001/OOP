#pragma once
#include <iostream>
#include <unordered_map>

class Window {
public:
  void setDescription(std::string str) { mDescription = str; }
  std::string getDescription() { return mDescription; }
  virtual void addWindow(char input, Window* windowPtr) = 0;
  virtual Window* nextWindow(char input) = 0;
  virtual void render() = 0;
protected:
  std::string mDescription; 
  std::unordered_map<char, Window*> mNext;
};

class WindowImpl : public Window {
public:
  void addWindow(char input, Window* windowPtr);
  Window* nextWindow(char input);
  virtual void render();
};

class AboutWindow : public WindowImpl {
public:
  void render();
};

class ViewDishesWindow : public WindowImpl {
public:
  void render();
};