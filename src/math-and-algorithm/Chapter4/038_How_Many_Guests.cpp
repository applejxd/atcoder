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
  vector<ll> A(N + 1);
  for (ll i = 1; i <= N; i++) {
    cin >> A[i];
  }
  vector<ll> L(Q + 1), R(Q + 1);
  for (ll i = 1; i <= Q; i++) {
    cin >> L[i] >> R[i];
  }

  vector<ll> sums(N + 1);
  sums[0] = 0;
  for (long long i = 1; i <= N; i++) {
    sums[i] = sums[i - 1ll] + A[i];
  }

  for (int i = 1; i <= Q; i++) {
    ll total = sums[R[i]] - sums[L[i] - 1ll];
    cout << total << endl;
  }

  return 0;
}