#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  ull R, C;
  cin >> R >> C;

  // 行・列 or y・x の順
  vector<ull> start(2);
  cin >> start[0] >> start[1];
  start[0]--;
  start[1]--;

  vector<ull> end(2);
  cin >> end[0] >> end[1];
  end[0]--;
  end[1]--;

  vector<vector<bool>> map(R, vector<bool>(C, false));
  vector<vector<ull>> graph(R * C, vector<ull>());
  for (ull row = 0; row < R; row++) {
    for (ull col = 0; col < C; col++) {
      char obj;
      cin >> obj;
      if (obj == '.') {
        map[row][col] = true;
        if (row > 0)
          if (map[row - 1][col]) {
            graph[row * C + col].push_back((row - 1) * C + col);
            graph[(row - 1) * C + col].push_back(row * C + col);
          }
        if (col > 0)
          if (map[row][col - 1]) {
            graph[row * C + col].push_back(row * C + col - 1);
            graph[row * C + col - 1].push_back(row * C + col);
          }
      } else if (obj == '#') {
        map[row][col] = false;
      }
    }
  }

  vector<ull> distances(R * C);
  std::queue<long long> targets;
  std::vector<bool> visited(graph.size(), false);
  long long start_node = start[0] * C + start[1];
  visited[start_node] = true;
  targets.push(start_node);
  while (!targets.empty()) {
    const auto current_node = targets.front();
    targets.pop();
    for (const auto& neighbor : graph[current_node]) {
      if (visited[neighbor]) continue;
      visited[neighbor] = true;
      targets.push(neighbor);

      distances[neighbor] = distances[current_node] + 1;
    }
  }

  cout << distances[end[0] * C + end[1]] << endl;

  return 0;
}