#include <iostream>

int main() {
  int N;
  std::cin >> N;
  if (N < 1 || N > 100) std::runtime_error("input error");

  std::cout << N + 5;
}