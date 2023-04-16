#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N, X;
  std::cin >> N >> X;

  std::vector<long long> A(N);
  for (long long i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  sort(A.begin(), A.end());
  long long a{0}, b{N - 1};

  if (X < A.front() || A.back() < X) {
    cout << "No" << endl;
    return 0;
  }

  while (a <= b) {
    long long middle = (b + a) / 2;

    if (X < A.at(middle)) {
      b = middle - 1;
    } else if (X > A.at(middle)) {
      a = middle + 1;
    } else {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}