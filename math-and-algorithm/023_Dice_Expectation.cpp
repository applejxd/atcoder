#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  std::cin >> N;

  std::vector<uint> B(N);
  for (uint i = 0; i < N; i++) {
    std::cin >> B.at(i);
  }

  std::vector<uint> R(N);
  for (uint i = 0; i < N; i++) {
    std::cin >> R.at(i);
  }

  double expect_b{0};
  for (const auto& b : B) {
    expect_b += b;
  }
  expect_b /= (double)(N);

  double expect_r{0};
  for (const auto& r : R) {
    expect_r += r;
  }
  expect_r /= (double)(N);

  cout << expect_b + expect_r;

  return 0;
}