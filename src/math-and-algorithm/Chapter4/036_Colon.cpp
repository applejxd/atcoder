#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  ll A, B, H, M;
  cin >> A >> B >> H >> M;

  double long_vel = 2. * M_PI / (12. * 60.);
  double short_vel = 2. * M_PI / 60.;

  double long_rad = long_vel * (H * 60. + M);
  double short_rad = short_vel * M;

  double long_x = A * cos(long_rad);
  double long_y = A * sin(long_rad);
  double short_x = B * cos(short_rad);
  double short_y = B * sin(short_rad);

  double distance = hypot(long_x - short_x, long_y - short_y);

  cout << fixed << setprecision(10) << distance << endl;

  return 0;
}