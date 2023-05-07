#pragma once
#include <iostream>
#include <vector>
#include "../view/Window.h"

/* Later on you might need more controllers.
  Then extract this class to get an abstract class.
  Apple: 1 controller for each view. */

class Controller {  
public:
  Controller(Window *firstWindow);
  std::string getUserInput();
  void run();
private:
  std::vector<Window*> mWindowStack;
};