/**
 * 総当たりの解法
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  std::cin >> N;

  std::vector<std::array<long long, 2>> points(N);
  for (long long i = 0; i < N; i++) {
    std::cin >> points.at(i).at(0) >> points.at(i).at(1);
  }

  // 総当りするケース
  double ans = hypot(points.at(1).at(0) - points.at(0).at(0),
                     points.at(1).at(1) - points.at(0).at(1));
  for (long long i = 0; i < N; i++) {
    for (long long j = 0; j < N; j++) {
      if (i == j) continue;

      double distance = hypot(points.at(i).at(0) - points.at(j).at(0),
                              points.at(i).at(1) - points.at(j).at(1));
      if (distance < ans) ans = distance;
    }
  }

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}