// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   long long N;
//   std::cin >> N;

//   std::vector<long long> A(N);
//   for (unsigned int i = 0; i < N; i++) {
//     std::cin >> A.at(i);
//   }

//   sort(A.begin(), A.end());

//   for (unsigned long long i = 0; i < A.size() - 1; ++i) {
//     std::cout << A.at(i) << " ";
//   }
//   cout << A.back() << endl;

//   return 0;
// }

#include <iostream>
using namespace std;

int N, A[200009], C[200009];

// A[l], A[l + 1], ..., A[r－1] を小さい順に整列する関数
void MergeSort(int l, int r) {
  // r－l=1 の場合、すでにソートされているので何もしない
  if (r - l == 1) return;
  // 2つに分割した後、小さい配列をソート
  int m = (l + r) / 2;
  MergeSort(l, m);
  MergeSort(m, r);

  // この時点で以下 の2つの配列がソートされている：
  // 列 A' に 相当するもの [A[l], A[l + 1], ..., A[m－1]]
  // 列 B' に 相当するもの [A[m], A[m + 1], ..., A[r－1]]
  // 以下が Merge 操作となります。
  int c1 = l, c2 = m, cnt = 0;
  while (c1 != m || c2 != r) {
    if (c1 == m) {
      // 列 A' が 空 の 場合
      C[cnt] = A[c2];
      c2++;
    } else if (c2 == r) {
      // 列 B' が空の場合（抜けている部分）
      C[cnt] = A[c1];
      c1++;
    } else {
      // そのいずれでもない場合（抜けている部分）
      if (A[c1] < A[c2]) {
        C[cnt] = A[c1];
        c1++;
      } else {
        C[cnt] = A[c2];
        c2++;
      }
    }
    cnt++;
  }

  // 列 A', 列 B' を合併した配列 C を A に移す
  // [C[0], ..., C[cnt－1]] －> [A[l], ..., A[r－1]]
  for (int i = 0; i < cnt; i++) A[l + i] = C[i];
}

int main() {
  // 入力
  cin >> N;
  for (unsigned int i = 1; i <= static_cast<unsigned int>(N); i++) cin >> A[i];

  // マージソート → 答えの出力
  MergeSort(1, N + 1);

  for (unsigned long long i = 1; i < static_cast<unsigned int>(N); ++i) {
    std::cout << A[i] << " ";
  }
  cout << A[N] << endl;

  return 0;
}
