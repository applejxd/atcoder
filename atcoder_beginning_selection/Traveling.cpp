#include <array>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  uint N;
  std::cin >> N;
  if (N < 1 || N > 1e+5) std::runtime_error("input error");

  std::vector<int> t_vec, x_vec, y_vec;
  for (uint idx = 0; idx < N; ++idx) {
    int t, x, y;
    std::cin >> t >> x >> y;
    if (t < 1 || t > 1e+5) std::runtime_error("input error");
    if (x < 0 || x > 1e+5) std::runtime_error("input error");
    if (y < 0 || y > 1e+5) std::runtime_error("input error");
    if (!(t_vec.empty())) {
      if (t_vec.back() > t) std::runtime_error("input error");
    }
    t_vec.push_back(t);
    x_vec.push_back(x);
    y_vec.push_back(y);
  }

  int t_pre = 0;
  int x_pre = 0;
  int y_pre = 0;
  for (uint idx = 0; idx < N; ++idx) {
    int t = t_vec.at(idx);
    int x = x_vec.at(idx);
    int y = y_vec.at(idx);

    int diff = (t - t_pre) - std::abs(x - x_pre) - std::abs(y - y_pre);
    if (diff < 0 || diff % 2 != 0) {
      std::cout << "No";
      return 0;
    }

    t_pre = t;
    x_pre = x;
    y_pre = y;
  }

  std::cout << "Yes";

  return 0;
}