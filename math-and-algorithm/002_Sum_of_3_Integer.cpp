#include <iostream>

int main() {
  int a1, a2, a3;
  std::cin >> a1 >> a2 >> a3;
  if (a1 < 1 || a1 > 100) std::runtime_error("input error");
  if (a2 < 1 || a2 > 100) std::runtime_error("input error");
  if (a3 < 1 || a3 > 100) std::runtime_error("input error");

  std::cout << a1 + a2 + a3;
}