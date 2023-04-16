/**
 * 配列から std::vector に変更 & リファクタ後
 */
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

// A[left]~A[right-1] をソート
void merge_sort(vector<ull>& A, uint left, uint right) {
  // ソート済
  if (right - left == 1) return;

  // 2つに分割 & 各々ソート
  uint middle = (left + right) / 2;
  merge_sort(A, left, middle);
  merge_sort(A, middle, right);

  vector<ull> sorted(right - left);
  // マージ操作(左半分は middle-1 まで・右半分は right-1 までスキャン)
  uint left_pos = left, right_pos = middle, idx = 0;
  while (left_pos < middle || right_pos < right) {
    if (left_pos == middle) {
      // 左半分探索終了
      sorted[idx] = A[right_pos];
      right_pos++;
    } else if (right_pos == right) {
      // 右半分探索終了
      sorted[idx] = A[left_pos];
      left_pos++;
    } else {
      // 左半分・右半分の先頭の大小を比較
      if (A[left_pos] < A[right_pos]) {
        // 左半分の先頭の方が小さい
        sorted[idx] = A[left_pos];
        left_pos++;
      } else {
        // 右半分の先頭の方が小さい
        sorted[idx] = A[right_pos];
        right_pos++;
      }
    }
    idx++;
  }

  copy(sorted.begin(), sorted.end(), A.begin() + left);
}

int main() {
  uint N;
  cin >> N;

  vector<ull> A(N);
  for (ull i = 0; i < N; ++i) cin >> A[i];

  merge_sort(A, 0, N);

  for (ull i = 0; i < N - 1; ++i) {
    cout << A[i] << " ";
  }
  cout << A[N - 1] << endl;

  return 0;
}