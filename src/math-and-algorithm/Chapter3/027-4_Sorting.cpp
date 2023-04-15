/**
 * 分割関数・統治関数を別実装
 */
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

template <typename T>
std::tuple<std::vector<T>, std::vector<T>> divide(const std::vector<T>& x) {
  uint middle = x.size() / 2;

  std::vector<T> a(middle), b(x.size() - middle);
  std::copy(x.begin(), x.begin() + middle, a.begin());
  std::copy(x.begin() + middle, x.end(), b.begin());

  return {a, b};
}

template <typename T>
std::vector<T> synthesize(const std::vector<T>& a, const std::vector<T>& b) {
  unsigned long long c1 = 0, c2 = 0, idx = 0;
  std::vector<T> ans(a.size() + b.size());
  while (c1 < a.size() || c2 < b.size()) {
    if (c1 == a.size()) {
      ans[idx] = b[c2];
      c2++;
    } else if (c2 == b.size()) {
      ans[idx] = a[c1];
      c1++;
    } else {
      if (a[c1] < b[c2]) {
        ans[idx] = a[c1];
        c1++;
      } else {
        ans[idx] = b[c2];
        c2++;
      }
    }
    idx++;
  }

  return ans;
}

template <typename T>
std::vector<T> conquer(const std::vector<T>& x) {
  if (x.size() <= 1) return x;

  std::vector<T> a, b;
  std::tie(a, b) = divide(x);
  a = conquer(a);
  b = conquer(b);
  return synthesize(a, b);
}

int main() {
  uint N;
  cin >> N;

  vector<ull> A(N);
  for (ull i = 0; i < N; ++i) cin >> A[i];

  // merge_sort(A, 0, N);
  A = conquer(A);

  for (ull i = 0; i < N - 1; ++i) {
    cout << A[i] << " ";
  }
  cout << A[N - 1] << endl;

  return 0;
}