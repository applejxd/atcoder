#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

using Point = valarray<ll>;
ll cross(Point pt0, Point pt1) { return pt0[0] * pt1[1] - pt0[1] * pt1[0]; }
ll dot(Point pt0, Point pt1) { return pt0[0] * pt1[0] + pt0[1] * pt1[1]; }
ll norm2(Point pt) { return pt[0] * pt[0] + pt[1] * pt[1]; }

// cf. https://hcpc-hokudai.github.io/archive/geometry_004.pdf
int ccw(Point a, Point b, Point c) {
  if (cross(b - a, c - a) > 0) return 1;
  if (cross(b - a, c - a) < 0) return -1;
  if (dot(b - a, c - a) < 0) return 2;
  if (norm2(b - a) < norm2(c - a)) return -2;
  return 0;
}

int main() {
  vector<ll> x(4), y(4);
  for (long long i = 0; i < 4; i++) {
    cin >> x[i] >> y[i];
  }

  Point pt0 = {x[0], y[0]};
  Point pt1 = {x[1], y[1]};
  Point pt2 = {x[2], y[2]};
  Point pt3 = {x[3], y[3]};

  if (ccw(pt0, pt1, pt2) * ccw(pt0, pt1, pt3) <= 0 &&
      ccw(pt2, pt3, pt0) * ccw(pt2, pt3, pt1) <= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}