#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  ll x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;

  double distance = hypot(x1 - x2, y1 - y2);
  ll smaller_radius = r1 <= r2 ? r1 : r2;
  ll larger_radius = r1 <= r2 ? r2 : r1;

  if (larger_radius > distance + smaller_radius) {
    cout << 1 << endl;
  } else if (larger_radius == distance + smaller_radius) {
    cout << 2 << endl;
  } else if (distance == smaller_radius + larger_radius) {
    cout << 4 << endl;
  } else if (distance >= smaller_radius + larger_radius) {
    cout << 5 << endl;
  } else {
    cout << 3 << endl;
  }

  return 0;
}