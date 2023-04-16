#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  // [0,N-1] -> [1,N]
  vector<bool> is_prime(N, true);
  is_prime.at(0) = false;

  // エラトステネスの篩
  for (int sieve = 2; sieve <= sqrt(N); ++sieve) {
    // 篩が素数でなければスキップ
    if(!is_prime.at(sieve-1)) continue;

    for (int times = 2; times <= N / sieve; ++times) {
      is_prime.at(sieve * times - 1) = false;
    }
  }

  for (int i = 0; i < N; i++) {
    if (is_prime.at(i)) {
      cout << i+1 << " ";
    }
  }
  cout << endl;

  return 0;
}