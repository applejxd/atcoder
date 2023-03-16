#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  cin >> N;

  for (int i = 2; i <= sqrt(N); i++) {
    if (N % i == 0) {
      cout << "No";
      return 0;
    }
  }

  cout << "Yes";
  return 0;
}