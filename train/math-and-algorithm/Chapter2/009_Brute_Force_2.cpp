#include <bits/stdc++.h>

using namespace std;

int main() {
  /** 入力 */

  int N, S;
  cin >> N >> S;

  vector<int> A;
  for (int idx = 0; idx < N; ++idx) {
    int tmp;
    cin >> tmp;
    // 目標値より低い値のみ保存
    if (tmp > S) continue;
    A.push_back(tmp);
  }

  // 動的計画法
  // A_1~A_i までの数字による和で得られるパターンを保存して
  // A_{i+1} までの数字による和で得られるパターンを計算

  vector<int> candidates = {0};
  for (auto &&a : A) {
    vector<int> new_candidates;

    for (auto &&elem : candidates) {
      new_candidates.push_back(elem);

      int tmp = elem + a;
      // 目標値より低い値のみ保存
      if (tmp < S) {
        new_candidates.push_back(tmp);
      } else if (tmp == S) {
        cout << "Yes";
        return 0;
      }
    }
    candidates = new_candidates;
  }

  cout << "No";

  return 0;
}