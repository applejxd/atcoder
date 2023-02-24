#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  std::cin >> N;

  std::vector<double> A(N);
  for (unsigned int i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  std::vector<double> B(N);
  for (unsigned int i = 0; i < N; i++) {
    std::cin >> B.at(i);
  }

  double ans{0};
  for (unsigned int i = 0; i < N; i++) {
    ans += A.at(i) / 3. + B.at(i) * 2. / 3.;
  }

  cout << fixed << setprecision(4) << ans << endl;

  return 0;
}