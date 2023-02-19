#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned long long N;
  cin >> N;

  vector<long long> A;
  for (size_t i = 0; i < N; i++) {
    long long tmp;
    cin >> tmp;
    A.push_back(tmp);
  }

  long long count{0};
  for (size_t i = 0; i < N; i++) {
    for (size_t j = i + 1; j < N; j++) {
      for (size_t k = j + 1; k < N; k++) {
        for (size_t l = k + 1; l < N; l++) {
          for (size_t m = l + 1; m < N; m++) {
            if (A.at(i) + A.at(j) + A.at(k) + A.at(l) + A.at(m) == 1000)
              count += 1;
          }
        }
      }
    }
  }

  cout << count;

  return 0;
}