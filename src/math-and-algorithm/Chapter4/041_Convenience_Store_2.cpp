#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  ll T, N;
  cin >> T >> N;

  // 階差を保存
  vector<ll> worker_list(T, 0);
  ll L, R;
  for (long long i = 0; i < N; i++) {
    cin >> L >> R;
    worker_list[L] += 1;
    worker_list[R] -= 1;
  }

  ll workers{0};
  for (long long i = 0; i < T; i++) {
    // 累積和を計算
    workers += worker_list[i];
    cout << workers << endl;
  }

  return 0;
}