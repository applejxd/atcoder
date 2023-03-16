/**
 * cf. https://atcoder.github.io/ac-library/production/document_ja/dsu.html
 */
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  ull N, Q;
  std::cin >> N >> Q;

  // 頂点数指定
  auto graph = dsu(N);

  ull t, u, v;
  for (ull i = 0; i < Q; i++) {
    cin >> t >> u >> v;
    if (t == 0) {
      // 辺追加
      graph.merge(u, v);
    } else {
      // 辺の有無判定
      if (graph.same(u, v)) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }

  return 0;
}