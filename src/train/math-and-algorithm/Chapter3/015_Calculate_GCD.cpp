#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  // ユークリッドの互除法
  while (A != 0 && B != 0) {
    if (A >= B) {
      A = A % B;
    } else {
      B = B % A;
    }
  }

  if (A == 0) {
    cout << B;
  } else {
    cout << A;
  }

  return 0;
}