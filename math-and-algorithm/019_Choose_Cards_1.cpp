#include <bits/stdc++.h>

using namespace std;

long long nc2(long long num) { return num * (num - 1) / 2; }

int main() {
  long long N;
  cin >> N;

  vector<long long> counts(3, 0);
  for (size_t i = 0; i < static_cast<size_t>(N); i++) {
    int tmp;
    cin >> tmp;
    if (tmp == 1) {
      counts.at(0) += 1;
    } else if (tmp == 2) {
      counts.at(1) += 1;
    } else if (tmp == 3) {
      counts.at(2) += 1;
    }
  }

  long long result{0};
  for (auto &&count : counts) {
    result += nc2(count);
  }

  cout << result;

  return 0;
}