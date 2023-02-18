#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> primes{};
  for (int i = 2; i <= N; i++) {
    // 素数フラグ
    bool is_prime = true;

    for (auto &&prime : primes) {
      if (i % prime == 0) {
        is_prime = false;
        break;
      }
    }

    if (is_prime) {
      primes.push_back(i);
    }
  }

  for (auto &&prime : primes) {
    cout << prime << " ";
  }
  cout << endl;

  return 0;
}