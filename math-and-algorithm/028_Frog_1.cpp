#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned long long N;
  std::cin >> N;

  std::vector<long long> h(N);
  for (unsigned long long i = 0; i < N; i++) {
    std::cin >> h.at(i);
  }

  vector<long long> costs(N);
  costs.at(0) = 0;
  costs.at(1) = abs(h.at(1) - h.at(0));

  for (unsigned long long i = 2; i < N; i++) {
    long long cost1 = costs.at(i - 1) + abs(h.at(i) - h.at(i - 1));
    long long cost2 = costs.at(i - 2) + abs(h.at(i) - h.at(i - 2));

    costs.at(i) = cost1 < cost2 ? cost1 : cost2;
  }

  cout << costs.back() << endl;

  return 0;
}