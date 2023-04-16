#include <bits/stdc++.h>

using namespace std;

/**
 * エラトステネスの篩
 */
vector<long long> soe(long long N) {
  // [0,N-1] -> [1,N]
  vector<bool> is_prime(N, true);
  is_prime.at(0) = false;

  for (long long sieve = 2; sieve <= sqrt(N); ++sieve) {
    // 篩が素数でなければスキップ
    if (!is_prime.at(sieve - 1)) continue;

    // 篩をかける
    for (long long times = 2; times <= N / sieve; ++times) {
      is_prime.at(sieve * times - 1) = false;
    }
  }

  vector<long long> primes;
  // [1,N] -> [0,N-1]
  for (long long i = 0; i < N; i++) {
    if (is_prime.at(i)) {
      primes.push_back(i + 1);
    }
  }

  return primes;
}

int main() {
  long long N;
  cin >> N;

  // 素数(因数)判定はsqrt(N) まで行えばいい
  const auto primes = soe(sqrt(N));

  vector<long long> factors;
  for (auto &&prime : primes) {
    while (fmod(N, prime) == 0) {
      factors.push_back(prime);
      N /= prime;
    }
  }
  if (N != 1) factors.push_back(N);

  for (auto &&factor : factors) {
    cout << factor << " ";
  }

  return 0;
}