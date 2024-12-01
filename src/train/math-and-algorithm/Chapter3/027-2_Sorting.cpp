/**
 * 標準ライブラリの sort を使用
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  std::cin >> N;

  std::vector<long long> A(N);
  for (unsigned int i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  sort(A.begin(), A.end());

  for (unsigned long long i = 0; i < A.size() - 1; ++i) {
    std::cout << A.at(i) << " ";
  }
  cout << A.back() << endl;

  return 0;
}
