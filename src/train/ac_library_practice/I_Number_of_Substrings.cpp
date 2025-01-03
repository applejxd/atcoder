#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
  string S;
  std::cin >> S;

  auto s_array = suffix_array(S);

  ll answer = 1LL * s_array.size() * (s_array.size() + 1) / 2;
  for (auto&& x : lcp_array(S, s_array)) {
    answer -= x;
  }
  cout << answer << endl;

  return 0;
}