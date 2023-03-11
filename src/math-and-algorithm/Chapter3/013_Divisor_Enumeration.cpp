#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  cin >> N;

  for (long long i = 1; i <= sqrt(N); i++) {
    if (N % i == 0) {
      cout << i << endl;
      cout << N / i << endl;
    }
  }

  return 0;
}