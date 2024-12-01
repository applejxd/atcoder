#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned long long n, r;
  cin >> n >> r;

  long long denominator{1};
  long long numerator{1};
  for (size_t i = 0; i < r; i++) {
    numerator *= n - i;
    denominator *= r - i;
  }
  cout << numerator / denominator;

  return 0;
}
