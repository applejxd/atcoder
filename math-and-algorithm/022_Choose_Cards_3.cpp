#include <bits/stdc++.h>

using namespace std;

int main() {
  constexpr long long total{100000};

  long long N;
  cin >> N;
  vector<long long> counts(total, 0);

  for (long long i = 0; i < N; i++) {
    long long tmp;
    cin >> tmp;
    counts.at(tmp)++;
  }

  long long result{0};
  for (long long i = 1; i < total / 2; i++) {
    result += counts.at(i) * counts.at(total - i);
  }
  result += counts.at(total / 2) * (counts.at(total / 2) - 1) / 2;

  cout << result;

  return 0;
}