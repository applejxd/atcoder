#include <bits/stdc++.h>

#include <Eigen/Dense>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using namespace Eigen;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ull H, W;
  cin >> H >> W;

  array<ull, 2> start_pos;
  vector<vector<char>> map(H, vector<char>(W, '.'));
  for (ull i = 0; i < H; i++) {
    for (ull j = 0; j < W; j++) {
      cin >> map[i][j];
      if (map[i][j] == 's') {
        start_pos = {i, j};
      }
    }
  }

  stack<array<ull, 2>> targets;
  vector<vector<bool>> visited(H, vector<bool>(W, false));
  visited[start_pos[0]][start_pos[1]] = true;
  targets.push(start_pos);

  while (!targets.empty()) {
    const auto target = targets.top();
    const ll i = target[0];
    const ll j = target[1];
    targets.pop();

    vector<array<ll, 2>> candidates = {
        {i - 1, j}, {i, j - 1}, {i + 1, j}, {i, j + 1}};
    for (const auto& [i_, j_] : candidates) {
      if (i_ < 0 || j_ < 0 || i_ >= ll(H) || j_ >= ll(W)) continue;
      if (visited[i_][j_]) continue;

      if (map[i_][j_] == '#') continue;
      if (map[i_][j_] == 'g') {
        cout << "Yes";
        return 0;
      }
      visited[i_][j_] = true;
      targets.push({ull(i_), ull(j_)});
    }
  }
  cout << "No";
  return 0;
}