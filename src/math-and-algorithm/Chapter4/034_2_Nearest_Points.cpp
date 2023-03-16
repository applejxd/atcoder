#include <bits/stdc++.h>

#include <atcoder/all>
#include <boost/geometry.hpp>
#include <boost/geometry/index/rtree.hpp>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

using point = bg::model::point<ll, 2, bg::cs::cartesian>;
using value = std::pair<point, ull>;

int main() {
  long long N;
  std::cin >> N;

  vector<value> points;
  for (long long i = 0; i < N; i++) {
    ll x, y;
    std::cin >> x >> y;
    points.push_back({point(x, y), i});
  }
  bgi::rtree<value, bgi::quadratic<16>> tree(points);

  double ans{-1};
  for (long long i = 0; i < N; i++) {
    auto query = points.at(i).first;
    vector<value> result;
    tree.query(bgi::nearest(query, 2), back_inserter(result));

    auto nearest = result.at(0).first;
    auto distance = bg::distance(query, nearest);
    if (ans < 0 || distance < ans) ans = distance;
  }

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}