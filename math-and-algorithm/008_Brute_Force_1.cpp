#include <iostream>

int main() {
  int N, S;
  std::cin >> N >> S;
  if (N < 1 || N > 1000) std::runtime_error("input error");
  if (S < 1 || S > 2000) std::runtime_error("input error");

  int count = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (i + j <= S) count++;
    }
  }

  std::cout << count;

  return 0;
}