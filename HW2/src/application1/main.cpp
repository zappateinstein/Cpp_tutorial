#include "igg_image/image.h"

#include <iostream>

/// Application 1: demonstrates the getter and setter via at().
int main() {
  std::cout << "=== Application 1: getter/setter test ===" << std::endl;
  igg::Image img(50, 50);

  // Reading through a const reference exercises the const (getter) overload.
  const igg::Image& const_img = img;
  std::cout << "Before set: img.at(49,49) = " << const_img.at(49, 49)
            << std::endl;

  // Assignment through the non-const overload exercises the setter.
  img.at(49, 49) = 50;

  std::cout << "After set:  img.at(49,49) = " << const_img.at(49, 49)
            << std::endl;
  return 0;
}
