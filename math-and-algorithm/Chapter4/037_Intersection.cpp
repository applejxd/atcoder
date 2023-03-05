#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

bool is_crossed(vector<ll> section, vector<ll> line) {
  // ax+by+c=0
  ll a = line[1] - line[3];
  ll b = line[2] - line[0];

  double value0 = a * (section[0] - line[0]) + b * (section[1] - line[1]);
  double value1 = a * (section[2] - line[0]) + b * (section[3] - line[1]);

  // 各線分が同一直線をなす場合
  if (abs(value0) < DBL_EPSILON && abs(value1) < DBL_EPSILON) {
    // 同一直線上にあるので x 軸だけで包含判定すればいい
    ll xl_max = max(line[0], line[2]);
    ll xl_min = min(line[0], line[2]);
    ll xs_max = max(section[0], section[2]);
    ll xs_min = min(section[0], section[2]);

    bool is_xl_min_in = (xl_min >= xs_min) && (xl_min <= xs_max);
    bool is_xl_max_in = (xl_max >= xs_min) && (xl_max <= xs_max);
    bool is_xs_min_in = (xs_min >= xl_min) && (xs_min <= xl_max);
    bool is_xs_max_in = (xs_max >= xl_min) && (xs_max <= xl_max);

    return is_xl_min_in || is_xl_max_in || is_xs_min_in || is_xs_max_in;
  }
  return value0 * value1 <= 0;
}

int main() {
  vector<ll> x(4), y(4);
  for (long long i = 0; i < 4; i++) {
    cin >> x[i] >> y[i];
  }
  bool is_crossed_a =
      is_crossed({x[0], y[0], x[1], y[1]}, {x[2], y[2], x[3], y[3]});
  bool is_crossed_b =
      is_crossed({x[2], y[2], x[3], y[3]}, {x[0], y[0], x[1], y[1]});

  if (is_crossed_a && is_crossed_b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}