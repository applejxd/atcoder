#include <iostream>
 
int main() {
  unsigned int a{1}, b{1};
  std::cin >> a >> b;
  if (a < 1 || b < 1 || 10000 < a || 10000 < b) {
    throw std::runtime_error("Input error!");
  }
 
  if (a*b % 2 == 0) {
    std::cout << "Even" << std::endl;
  } else {
    std::cout << "Odd" << std::endl;
  }
 
  return 0;
}
