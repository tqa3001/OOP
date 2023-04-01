#include <vector> 
#include <cassert> 
#include "./src/hw.cpp"
// using namespace std;

class testMessage {
  void test() {
    for (char i = 'a'; i <= 'z'; i = char(i + 1)) {
      for (char j = 'a'; j < 'z'; j = char(j + 1)) {
        Message T(string(1, i), string(1, j)); 
        assert(T.msg() == char(i) + ": " + char(j)); 
      }
    }
    cout << "Message passes all tests\n"; 
  }
}; 

class testMain {

};