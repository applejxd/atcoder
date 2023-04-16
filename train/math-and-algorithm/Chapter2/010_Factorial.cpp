#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  // オーバーフローに注意
  long long prod = 1;
  for (int i = 1; i <= N; i++) {
    prod *= i;
  }

  cout << prod;

  return 0;
}