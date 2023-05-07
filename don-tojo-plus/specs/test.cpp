#include <iostream>
#include <vector>
using namespace std;

class Thing {
public:
  int getValue() {
    return value;
  }
  // Thing() { value = 5; }
private:
  static int value;
};

int Thing::value;

int main() {
  vector<int> vec = {1, 2, 3};
  /* this does not work, erase needs a pointer, you gave a const_iterator */
  /* pointers != iterators, though pointers are a form of iterators */
  /*
  for (auto &x : vec) {  
    if (x == 2) {
      vec.erase(&x);
      break;
    }
  }
  */ 
  for (auto &x : vec) {
    cout << x << ' ';
  }
  Thing thing;
  cout << thing.getValue();
}