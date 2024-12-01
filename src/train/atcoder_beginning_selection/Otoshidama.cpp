#include <cmath>
#include <iostream>

int main() {
  uint N = 0;
  uint Y = 0;
  std::cin >> N >> Y;
  if (N < 1 || N > 2000) {
    throw std::runtime_error("N input error!");
  }
  if (Y < 1000 || Y % 1000 != 0 || std::log10(Y / 2) > 7) {
    throw std::runtime_error("Y input error!");
  }

  for (uint x = 0; x <= N; ++x) {
    for (uint y = 0; y <= N - x; ++y) {
      uint z = N - x - y;
      const uint price = x * 10000 + y * 5000 + z * 1000;
      if (price == Y) {
        std::cout << x << " " << y << " " << z;
        return 0;
      }
    }
  }
  std::cout << "-1 -1 -1";

  return 0;
}
