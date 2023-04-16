#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  std::cin >> N;

  std::vector<unsigned int> B(N);
  for (unsigned int i = 0; i < N; i++) {
    std::cin >> B.at(i);
  }

  std::vector<unsigned int> R(N);
  for (unsigned int i = 0; i < N; i++) {
    std::cin >> R.at(i);
  }

  double expect{0};
  for (const auto& b : B) {
    expect += static_cast<double>(b) / N;
  }
  for (const auto& r : R) {
    expect += static_cast<double>(r) / N;
  }

  cout << fixed << setprecision(7) << expect << endl;

  return 0;
}