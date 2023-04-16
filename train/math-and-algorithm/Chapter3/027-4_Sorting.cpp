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

std::tuple<std::vector<ull>, std::vector<ull>> divide(
    const std::vector<ull>& x) {
  unsigned long long center = x.size() / 2;
  std::vector<ull> l(x.begin(), x.begin() + center);
  std::vector<ull> r(x.begin() + center, x.end());
  return {l, r};
}

vector<ull> conquer(const std::vector<ull>& list) {
  if (list.size() <= 1) return list;

  auto [a, b] = divide(list);
  a = conquer(a);
  b = conquer(b);

  // merge operations
  unsigned long long c1 = 0, c2 = 0, idx = 0;
  std::vector<ull> ans(a.size() + b.size());
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