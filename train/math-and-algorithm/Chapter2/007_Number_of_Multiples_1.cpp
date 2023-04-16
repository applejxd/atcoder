#include <iostream>

int main() {
  int N, X, Y;
  std::cin >> N >> X >> Y;
  if (N < 1 || N > 1e+6) std::runtime_error("input error");
  if (X < 1 || X > 1e+6) std::runtime_error("input error");
  if (Y < 1 || Y > 1e+6 || X >= Y) std::runtime_error("input error");

  int count = 0;
  for (int idx = 1; idx <= N; ++idx) {
    if (idx % X == 0 || idx % Y == 0) ++count;
  }

  std::cout << count;
}