#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  ll N, Q;
  cin >> N >> Q;

  // diff[0], diff[N] は便宜上の padding. 出力しない.
  vector<ll> diff(N + 1, 0);
  for (long long i = 0; i < Q; i++) {
    ll L, R, X;
    cin >> L >> R >> X;

    diff[L - 1] += X;
    diff[R] -= X;
  }

  for (ll i = 1; i < static_cast<ll>(diff.size()) - 1; ++i) {
    auto elem = diff[i];
    if (elem < 0) {
      cout << ">";
    } else if (elem > 0) {
      cout << "<";
    } else {
      cout << "=";
    }
  }
  cout << endl;

  return 0;
}