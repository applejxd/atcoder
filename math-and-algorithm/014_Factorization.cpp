#include <bits/stdc++.h>

using namespace std;

vector<int> get_factors(long long N) {
  vector<int> factors;
  for (int i = 2; i <= sqrt(N); i++) {
    if (N % i == 0) {
      factors.push_back(i);
      factors.push_back(N / i);
    }
  }
  return factors;
}

vector<int> factorization(vector<int> factors) {
  const auto new_factors = factorization(Z)
}

int main() {
  long long N;
  cin >> N;

  return 0;
}