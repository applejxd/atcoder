#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  ull T;
  std::cin >> T;

  for (unsigned long long i = 0; i < T; i++) {
    ull N, M, A, B;
    cin >> N >> M >> A >> B;

    cout << floor_sum(N, M, A, B) << endl;
  }

  return 0;
}