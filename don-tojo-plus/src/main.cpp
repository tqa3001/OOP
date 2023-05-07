#include <iostream>
#include "./view/Window.h"
#include "./controller/Controller.h"
using std::cout;

main() {
  StartingWindow window;
  Controller controller = Controller(&window);
  controller.run();
  return 0; 
}