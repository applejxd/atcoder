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

  std::vector<std::vector<long long>> graph(N);
  std::vector<long long> A(M), B(M);
  for (long long i = 0; i < M; i++) {
    std::cin >> A[i] >> B[i];
    graph[A[i] - 1].emplace_back(B[i] - 1);
    graph[B[i] - 1].emplace_back(A[i] - 1);
  }

  vector<ll> distances(N, -1);

  std::queue<long long> targets;
  std::vector<bool> visited(graph.size(), false);
  long long start_node = 0;
  visited[start_node] = true;
  distances[start_node] = 0;
  targets.push(start_node);
  while (!targets.empty()) {
    const auto current_node = targets.front();
    targets.pop();
    for (const auto& neighbor : graph[current_node]) {
      if (visited[neighbor]) continue;
      visited[neighbor] = true;
      distances[neighbor] = distances[current_node] + 1;
      targets.push(neighbor);
    }
  }

  for (long long i = 0; i < N; i++) {
    cout << distances[i] << endl;
  }

  return 0;
}