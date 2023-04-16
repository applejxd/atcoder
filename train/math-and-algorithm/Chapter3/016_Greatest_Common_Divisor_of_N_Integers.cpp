#include <bits/stdc++.h>

using namespace std;

long long gcd(long long A, long long B) {
  // ユークリッドの互除法
  while (A != 0 && B != 0) {
    if (A >= B) {
      A = A % B;
    } else {
      B = B % A;
    }
  }

  if (A == 0) {
    return B;
  } else {
    return A;
  }
}

int main() {
  int N;
  cin >> N;

  long long ans{-1};
  for (size_t i = 0; i < static_cast<size_t>(N); i++) {
    long long tmp;
    cin >> tmp;

    if (ans < 0) {
      ans = tmp;
    } else {
      ans = gcd(ans, tmp);
    }
  }

  cout << ans;

  return 0;
}