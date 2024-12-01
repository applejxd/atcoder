#include <iostream>
#include <vector>

int main() {
  unsigned int N, A, B;
  {
    std::cin >> N >> A >> B;
    if (N * A * B == 0 || 1e+4 < N || B < A || 36 < A || 36 < B) {
      throw std::runtime_error("Input Error!");
    }
  }

  unsigned int ans{0};
  for (unsigned int n=1; n <= N; ++n) {
    unsigned int sum{0};
    unsigned int tmp_n{n};
    while(1) {
      unsigned int digit = tmp_n % 10;
      sum += digit;
      if (digit == tmp_n) {
        break;
      }
      tmp_n = (tmp_n-digit)/10;
    }

    if (A <= sum && sum <= B) {
      ans += n;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}