#include <iostream>
#include <vector>

int main() {
  // 操作対象
  std::vector<unsigned int> A;

  // 入力処理
  {
    std::string input{""};
    std::cin >> input;
    const int N = std::stoi(input);
    if (N < 1 || 200 < N) {
      throw std::runtime_error("Input Error!");
    }

    for (int idx = 0; idx < N; ++idx) {
      unsigned int a;
      std::cin >> a;
      A.push_back(a);
    }
  }

  // 回答
  unsigned int ans{0};

  while (1) {
    for (auto iter=A.begin(); iter<A.end(); ++iter) {
      if (*iter % 2 == 0) {
        *iter /= 2;
      } else {
        std::cout << ans;
        return 0;
      }
    }
    ++ans;
  }
  
  std::cout << ans;
  return 0;
}
