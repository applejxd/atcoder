#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  uint N;
  std::cin >> N;
  if (N < 1 || N > 100) {
    throw std::runtime_error("N input error!");
  }

  std::vector<uint> d;
  for (uint idx = 0; idx < N; ++idx) {
    uint d_i = 0;
    std::cin >> d_i;
    if (d_i < 1 || d_i > 100) {
      throw std::runtime_error("d input error!");
    }
    d.push_back(d_i);
  }

  std::sort(d.begin(), d.end());

  uint stack_num = 0;
  uint pre_size = 0;
  for (const auto& d_i : d) {
    if (pre_size != 0 && d_i == pre_size) continue;
    pre_size = d_i;
    stack_num++;
  }

  std::cout << stack_num;
}