#include <iostream>
#include <string>
#include <unordered_map>
#include "./Window.cpp"
using std::cout, std::cin, std::pair, std::unordered_map, std::string;

class WindowMenu {
public:
  WindowMenu() {}
  void add(char buttonPressed, Window window) {
    M[buttonPressed] = window;
  }
  void print() {
    for (auto T : M) {
      cout << "[" << T.first << "] - " << T.second.getDescription() << '\n';
    }
  }
  int execute() {
    /* -1 -> bad input, 0 -> ok, 1 -> exit */
    char input; cin >> input;
    if (input == 'x')
      return 1; 
    auto pt = M.find(input); 
    if (pt == M.end())
      return -1;
    (*pt).second.run(); 
    return 0; 
  }
private:
  unordered_map<char, Window> M;
};


