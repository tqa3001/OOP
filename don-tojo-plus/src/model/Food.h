#pragma once
#include <iostream>

class Food {
public:
  std::string getName() { return name; }
  std::string getDescription();
  bool operator== (const Food& oth) {
    return name == oth.name;
  }
private:
  std::string name;
  std::string rice, noodle;
  std::string meat;
  std::string vegetable;
  std::string soup;
};

class FoodBuilder {
public:
  void reset();
  virtual void addMeat() = 0;
  virtual void addVegetable() = 0;
  virtual void addSoup() = 0;
  virtual void nameAs() = 0;
private: 
  Food result;
};

class FoodDirector {
public:
  FoodDirector(FoodBuilder &builder) : builder(builder) {}
  void changeBuildler(FoodBuilder &builder);
  void makeFood(std::string type);
private:
  FoodBuilder &builder;
};

class DonBuilder : public FoodBuilder {
public:
  void addRice();
};

class UdonBuilder : public FoodBuilder {
public:
  void addNoodle();
};