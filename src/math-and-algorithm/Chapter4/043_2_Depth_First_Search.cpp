#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

template <typename T>
void dfs(const std::vector<std::vector<T>>& graph, T start_node,
         std::vector<bool>& visited) {
  std::stack<T> targets;
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
}

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> A(M), B(M);
  // 隣接リスト表現
  vector<vector<ll>> neighbor_list(N);
  for (long long i = 0; i < M; i++) {
    cin >> A[i] >> B[i];

    // 頂点A[i]の隣接頂点にB[i]を追加
    neighbor_list[A[i] - 1].emplace_back(B[i] - 1);
    // 上記の逆
    neighbor_list[B[i] - 1].emplace_back(A[i] - 1);
  }

  // 訪問済フラグ
  vector<bool> visited_list(N, false);
  // 0 の連結成分にすべて訪問済フラグを付与
  dfs(neighbor_list, 0ll, visited_list);

  for (auto&& visited : visited_list) {
    if (visited) continue;
    cout << "The graph is not connected." << endl;
    return 0;
  }
  cout << "The graph is connected." << endl;
  return 0;
}