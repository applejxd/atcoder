#include <iostream>

int main() {
  unsigned int A, B, C, X;
  // 入力
  {
    std::cin >> A;
    if (50 < A) {
      throw std::runtime_error("Input Error of A.");
    }

    std::cin >> B;
    if (50 < B) {
      throw std::runtime_error("Input Error of B.");
    }

    std::cin >> C;
    if (50 < C) {
      throw std::runtime_error("Input Error of C.");
    }

    if (A + B + C < 1) {
      throw std::runtime_error("Input Error of A, B, C.");
    }

    std::cin >> X;
    if (X < 50 || 20000 < X || X % 50 != 0) {
      throw std::runtime_error("Input Error of X.");
    }
  }

  unsigned int ans{0};
  for (unsigned int a = 0; a <= A; ++a) {
    for (unsigned int b = 0; b <= B; ++b) {
      for (unsigned int c = 0; c <= C; ++c) {
        if (500 * a + 100 * b + 50 * c == X) {
          ++ans;
        }
      }
    }
  }

  std::cout << ans;

  return 0;
}