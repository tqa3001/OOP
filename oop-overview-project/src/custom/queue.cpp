// For practice using templates + reimplement basic data structures. 
// Why did I try to compile this lol 
// std::list or std::vector?? 
#include <iostream>
using namespace std;

template<class T>
class Queue {

private: 
  int sz; 
  struct Item {
    T data; 
    Item *next; 
    Item() {}
    Item(T x) : data(x) { next = NULL; }; 
  }; 
  Item *temp, *head, *tail; 
  /** Bug: Item* a, b => Item *a, *b; 
   * Reason: declaration mirrors use. int a[10], b[10]; not int[10] a, b;
  */
public:
  Queue() { sz = 0; }
  int size() { return sz; }
  void push(T x); 
  void pop(); 
  T front(); 
  ~Queue() { while (size()) pop(); }
}; 

template<class T>
void Queue<T>::push(T x) {
  temp = new Item(x); 
  if (!sz) {
    head = tail = temp; 
  } else {
    tail->next = temp; 
    tail = temp; 
  }
  sz++; 
}

template<class T>
void Queue<T>::pop() { 
  if (!sz) throw "Error: Cannot pop() an empty queue.";
  Item* new_head = head->next; 
  delete head; 
  head = new_head; 
  sz--; 
} 

template<class T>
T Queue<T>::front() { 
  if (!sz) throw "Error: Cannot get front() of an empty queue.";
  return head->data; 
}