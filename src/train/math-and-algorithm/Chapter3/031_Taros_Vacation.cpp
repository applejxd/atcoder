#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned long long N;
  std::cin >> N;

  std::vector<long long> A(N);
  for (unsigned long long i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  vector<long long> grow(N, 0);
  grow.at(0) = A.at(0);
  grow.at(1) = max(A.at(0), A.at(1));

  for (unsigned long long i = 2; i < N; i++) {
    grow.at(i) = max(grow.at(i - 1), grow.at(i - 2) + A.at(i));
  }

  cout << grow.back() << endl;

  return 0;
}