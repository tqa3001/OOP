// TODO: Put this in GoogleTest
#include <iostream> 
#include <string> 
#include "../src/custom/queue.cpp"
#include <cassert> 
using namespace std;

class TestQueue {
private: 
  // Arrange
  string ans = ""; 
  Queue<int> Q; 
  void add_front() { ans += to_string(Q.front()) + " "; }
public: 
  void test() {
  // Act
    Q.push(5); 
    Q.push(36); 
    add_front(); 
    Q.push(19); 
    add_front(); 
    Q.pop(); 
    add_front(); 
    Q.push(11); 
    Q.push(-132); 
    Q.pop(); 
    while (Q.size()) {
      add_front(); 
      Q.pop(); 
    }
  // Assert
    cout << "ans: " << ans << '\n'; 
    assert(ans == "5 5 36 19 11 -132 "); 
  }
}; 

int main() {
  TestQueue Test; 
  Test.test(); 
  return 0; 
}
