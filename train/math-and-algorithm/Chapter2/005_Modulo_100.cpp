#include <iostream>
#include <vector>

int main() {
  uint N;
  std::cin >> N;
  if (N < 1 || N > 50) std::runtime_error("input error");

  int sum=0;
  for (uint idx = 0; idx < N; ++idx) {
    int tmp;
    std::cin >> tmp;
    if (tmp < 1 || tmp > 100) std::runtime_error("input error");
    sum += tmp;
  }
  std::cout << sum % 100;
}