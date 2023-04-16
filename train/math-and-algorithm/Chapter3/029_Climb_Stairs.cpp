#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned int N;
  std::cin >> N;

  if (N == 1) {
    cout << "1" << endl;
    return 0;
  }
  if (N == 2) {
    cout << "2" << endl;
    return 0;
  }

  vector<int> patterns(N);
  patterns.at(0) = 1;
  patterns.at(1) = 2;

  for (unsigned int i = 2; i < N; i++) {
    patterns.at(i) = patterns.at(i - 1) + patterns.at(i - 2);
  }

  cout << patterns.back() << endl;

  return 0;
}