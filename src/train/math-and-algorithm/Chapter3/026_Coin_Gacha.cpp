#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  std::cin >> N;

  // まずは1枚引く
  double ans{1};
  for (long long i = 1; i < N; i++) {
    // 新しい種類のコインを引く期待値 (無限等比級数の公式を利用)
    ans += static_cast<double>(N) / (N - i);
  }
  cout << fixed << setprecision(7) << ans << endl;

  return 0;
}