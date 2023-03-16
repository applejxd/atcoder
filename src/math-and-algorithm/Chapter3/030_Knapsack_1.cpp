#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N, W;
  std::cin >> N >> W;

  vector<vector<long long>> memory(N + 1, vector<long long>(W + 1, 0));
  // i=0は未使用
  for (long long i = 1; i <= N; i++) {
    long long w, v;
    cin >> w >> v;

    // 重さ(0,...,W)
    for (long long j = 0; j <= W; j++) {
      if (j - w >= 0) {
        // 品物が足せる
        memory.at(i).at(j) =
            max(memory.at(i - 1).at(j), memory.at(i - 1).at(j - w) + v);
      } else {
        // 品物が足せない -> 1個品物が少ないケースをそのままコピー
        memory.at(i).at(j) = memory.at(i - 1).at(j);
      }
    }
  }

  long long ans{0};
  for (auto&& elem : memory.back()) {
    ans = max(ans, elem);
  }
  cout << ans << endl;

  return 0;
}