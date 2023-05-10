#include "payment.h"
#include <string>
#include <chrono>
#include <ctime>

/* https://en.cppreference.com/w/cpp/chrono/time_point/time_since_epoch */
void Payment::timestamp() {
  auto timepoint = std::chrono::system_clock::now();
  std::time_t now = std::chrono::system_clock::to_time_t(timepoint);
  mTime = std::ctime(&now);
}

void Payment::render() {
  std::cout << "=== On " << mTime << " ===\n";
  std::cout << "Total: $" << mPrice << '\n';
  std::cout << "Items: ";
  for (auto& item : mItems) {
    std::cout << item.getName() << " - $" << std::to_string(item.getCount() * item.getPrice()) << '\n';
  }
  std::cout << '\n';
}

std::vector<Item> Payment::getItems() { return mItems; }