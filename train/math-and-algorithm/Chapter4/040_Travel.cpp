#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N - 1);
  for (long long i = 0; i < N - 1; i++) {
    cin >> A[i];
  }

  ll M;
  cin >> M;
  vector<ll> B(M);
  for (long long i = 0; i < M; i++) {
    cin >> B[i];
  }

  // 0駅目からの累積距離
  vector<ll> d(N, 0);
  for (long long i = 0; i < N; i++) {
    d[i + 1] = d[i] + A[i];
  }

  ll result{0};
  for (long long i = 1; i < M; i++) {
    result += abs(d[B[i] - 1] - d[B[i - 1] - 1]);
  }
  cout << result << endl;

  return 0;
}