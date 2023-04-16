#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  ull N, M;
  cin >> N >> M;

  std::vector<std::vector<long long>> graph(N);
  std::vector<long long> a(M), b(M);
  for (long long i = 0; i < M; i++) {
    std::cin >> a[i] >> b[i];
    graph[a[i] - 1].emplace_back(b[i] - 1);
    graph[b[i] - 1].emplace_back(a[i] - 1);
  }

  uint ans = 0;
  for (ull i = 0; i < N; i++) {
    const auto neighbors = graph[i];
    ull count = 0;
    for (const auto& neighbor : neighbors) {
      if (neighbor < i) count++;
    }
    if (count == 1) ans++;
  }
  cout << ans << endl;

  return 0;
}