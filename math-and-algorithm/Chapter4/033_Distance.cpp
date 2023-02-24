#include <bits/stdc++.h>

using namespace std;

int main() {
  long long ax, ay, bx, by, cx, cy;
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> cx >> cy;

  vector<long long> bc_diff = {cx - bx, cy - by};
  vector<long long> ab_diff = {bx - ax, by - ay};
  vector<long long> ca_diff = {ax - cx, ay - cy};

  bool is_abc_acute =
      -bc_diff.at(0) * ab_diff.at(0) - bc_diff.at(1) * ab_diff.at(1) >= 0;
  bool is_acb_acute =
      -bc_diff.at(0) * ca_diff.at(0) - bc_diff.at(1) * ca_diff.at(1) >= 0;

  double ans;
  if (!is_abc_acute) {
    ans = hypot(ab_diff.at(0), ab_diff.at(1));
  } else if (!is_acb_acute) {
    ans = hypot(ca_diff.at(0), ca_diff.at(1));
  } else {
    double norm = hypot(bc_diff.at(0), bc_diff.at(1));
    vector<double> normal = {bc_diff.at(1) / norm, -bc_diff.at(0) / norm};

    double c = -(normal.at(0) * bx + normal.at(1) * by);
    ans = abs(normal.at(0) * ax + normal.at(1) * ay + c);
  }
  cout << fixed << setprecision(7) << ans << endl;

  return 0;
}