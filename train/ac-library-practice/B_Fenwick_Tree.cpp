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

  // フェニックス木作成
  auto tree = fenwick_tree<ll>(N);
  for (unsigned long long i = 0; i < N; i++) {
    ll tmp;
    std::cin >> tmp;
    tree.add(i, tmp);
  }

  // クエリ処理
  for (unsigned long long i = 0; i < Q; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    if (x == 0) {
      // 値追加
      tree.add(y, z);
    } else {
      // 総和出力
      cout << tree.sum(y, z) << endl;
    }
  }

  return 0;
}