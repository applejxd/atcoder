#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned int N;
  std::cin >> N;

  double ans{0};
  for (unsigned int i = 0; i < N; i++) {
    double P, Q;
    std::cin >> P >> Q;
    ans += Q / P;
  }

  cout << fixed << setprecision(7) << ans << endl;

  return 0;
}