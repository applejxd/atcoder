#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> A(M), B(M);
  vector<vector<ll>> graph(N);
  for (long long i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    graph[A[i]].emplace_back(B[i]);
    graph[B[i]].emplace_back(A[i]);
  }

  for (long long k = 0; k < N; k++) {
    vector<ll> length(N, -1);
    std::queue<ll> targets;
    length[0] = 0;
    targets.push(0);
    while (!targets.empty()) {
      const auto current_node = targets.front();
      targets.pop();
      for (const auto& neighbor : graph[current_node]) {
        if (length[neighbor] >= 0) continue;
        length[neighbor] = length[current_node] + 1;
        targets.push(neighbor);
      }
    }
  }

    return 0;
}