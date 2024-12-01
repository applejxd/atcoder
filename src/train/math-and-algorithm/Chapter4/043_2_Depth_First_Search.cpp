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
  // 隣接リスト表現
  vector<vector<ll>> graph(N);
  for (long long i = 0; i < M; i++) {
    cin >> A[i] >> B[i];

    // 頂点A[i]の隣接頂点にB[i]を追加
    graph[A[i] - 1].emplace_back(B[i] - 1);
    // 上記の逆
    graph[B[i] - 1].emplace_back(A[i] - 1);
  }

  std::stack<long long> targets;
  std::vector<bool> visited(graph.size(), false);
  long long start_node = 0;
  visited[start_node] = true;
  targets.push(start_node);
  while (!targets.empty()) {
    const auto current_node = targets.top();
    targets.pop();
    for (const auto& neighbor : graph[current_node]) {
      if (visited[neighbor]) continue;
      visited[neighbor] = true;
      targets.push(neighbor);
    }
  }

  for (auto&& visited : visited) {
    if (visited) continue;
    cout << "The graph is not connected." << endl;
    return 0;
  }
  cout << "The graph is connected." << endl;
  return 0;
}