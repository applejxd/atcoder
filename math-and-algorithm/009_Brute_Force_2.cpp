#include <iostream>
#include <vector>

int main() {
  int N, S;
  std::cin >> N >> S;

  std::vector<int> A;
  for (int idx = 0; idx < N; ++idx) {
    int tmp;
    std::cin >> tmp;
    // 目標値より低い値のみ保存
    if (tmp > S) continue;
    A.push_back(tmp);
  }

  

  return 0;
}