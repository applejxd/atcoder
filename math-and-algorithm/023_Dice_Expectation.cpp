#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  std::cin >> N;

  std::vector<uint> B;
  for (uint i = 0; i < N; i++) {
    uint N;
    std::cin >> N;
    B.push_back(N);
  }

  std::vector<uint> R;
  for (uint i = 0; i < N; i++) {
    uint N;
    std::cin >> N;
    R.push_back(N);
  }

  double expect{0};
  for (const auto& b : B) {
    for (const auto& r : R) {
      expect += (double)(b + r) / pow(double(N), 2);
    }
  }
  cout << expect;

  return 0;
}