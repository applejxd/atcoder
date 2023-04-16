#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

ll soe_sum(long long N) {
  ll ans = 0;
  for (long long sieve = 1; sieve <= N; ++sieve) {
    // 篩をかける
    for (long long times = 1; times <= N / sieve; ++times) {
      ans += sieve * times;
    }
  }
  return ans;
}

int main() {
  long long N;
  cin >> N;

  const auto ans = soe_sum(N);
  cout << ans << endl;

  return 0;
}