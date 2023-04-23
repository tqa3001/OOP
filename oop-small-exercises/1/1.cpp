/**
 * Write a program that defines a shape class with a constructor that gives value to width and height. 
 * The define two sub-classes triangle and rectangle, that calculate the area of the shape area (). 
 * In the main, define two variables a triangle and a rectangle and then call the area() function in this 
 * two varibles.
*/

#include <iostream>
using namespace std;

class Shape {
public:
  int width, height; 
  Shape(int width, int height) : width(width), height(height) {}; 
}; 

class Triangle : public Shape {
public: 
  using Shape::Shape;  // c++11 
  int area() { return this->width * this->height / 2; }
}; 

class Rectangle : public Shape {
public: 
  using Shape::Shape; 
  int area() { return this->width * this->height; }
}; 

signed main() {
  Triangle A(6, 4); 
  Rectangle B(3, 10); 
  cout << A.area() << ' ' << B.area(); 
}