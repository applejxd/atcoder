#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  cin >> N;

  vector<long long> counts(4, 0);
  for (size_t i = 0; i < static_cast<size_t>(N); i++) {
    int tmp;
    cin >> tmp;
    if (tmp == 100) {
      counts.at(0) += 1;
    } else if (tmp == 200) {
      counts.at(1) += 1;
    } else if (tmp == 300) {
      counts.at(2) += 1;
    } else if (tmp == 400) {
      counts.at(3) += 1;
    }
  }

  cout << counts.at(0) * counts.at(3) + counts.at(1) * counts.at(2);

  return 0;
}