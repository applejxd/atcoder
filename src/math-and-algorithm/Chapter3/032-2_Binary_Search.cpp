#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  long long N, X;
  std::cin >> N >> X;

  std::vector<long long> A(N);
  for (long long i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  sort(A.begin(), A.end());
  if (binary_search(A.begin(), A.end(), X)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}