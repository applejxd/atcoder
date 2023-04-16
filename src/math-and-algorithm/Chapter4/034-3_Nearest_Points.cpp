/**
 * http://aoba.cc.saga-u.ac.jp/lecture/Algorithms/text/ClosestPair.pdf
 */
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using Point = array<ll, 2>;

double distance(Point a, Point b) { return hypot(a[0] - b[0], a[1] - b[1]); }

// axis 方向にソート・分割
std::tuple<std::vector<Point>, std::vector<Point>> divide(
    std::vector<Point>& points, uint axis) {
  // 軸を指定してソート
  std::sort(points.begin(), points.end(),
            [&](Point a, Point b) { return a[axis] < b[axis]; });

  ull middle = points.size() / 2;
  std::vector<Point> left(points.begin(), points.begin() + middle);
  std::vector<Point> right(points.begin() + middle, points.end());
  return {left, right};
}

double conquer(std::vector<Point>& x, uint axis) {
  if (x.size() == 2) return distance(x[0], x[1]);
  // 3点は総当り(3点以下を分割すると1点の部分が出るため3点で実施)
  if (x.size() == 3) {
    double a = distance(x[0], x[1]), b = distance(x[1], x[2]),
           c = distance(x[2], x[0]);
    return min({a, b, c});
  }

  // 軸をフリップ
  axis = (axis + 1) % 2;

  // 分割したパート毎に最小距離計算 & 比較
  auto [left, right] = divide(x, axis);
  const double da = conquer(left, axis), db = conquer(right, axis);
  double ans = min({da, db});

  // 分割境界付近に関する処理
  {
    // 境界付近に最小距離候補が存在
    // => 少なくとも分割方向距離は暫定の最小距離未満
    const double l = left.back()[axis], r = right.front()[axis];
    if (abs(r - l) > ans) return ans;

    ll c = (r + l) / 2;
    std::vector<Point> ln, rn;
    // 境界に近い点を抽出
    for (const auto& elem : left)
      if (abs(elem[axis] - c) < ans) ln.push_back(elem);
    for (const auto& elem : right)
      if (abs(elem[axis] - c) < ans) rn.push_back(elem);

    // 総当り探索
    for (const auto& i : ln) {
      for (const auto& j : rn) {
        double d = distance(i, j);
        ans = min({ans, d});
      }
    }
  }

  return ans;
}

int main() {
  long long N;
  std::cin >> N;

  std::vector<std::array<ll, 2>> points(N);
  for (long long i = 0; i < N; i++) {
    std::cin >> points.at(i).at(0) >> points.at(i).at(1);
  }

  double ans = conquer(points, 0);
  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}