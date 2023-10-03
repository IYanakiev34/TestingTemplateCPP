#include <iostream>
#include <lib.h>

int main(int argc, char **argv) {
  std::cout << "Hello from Gtest example\n";
  std::cout << "Sum library sum(2,3): " << sum(2, 3) << '\n';
  return 0;
}
