#include <iostream>
#include <vector>
#include <string>
#include <regex>

int main() {
  std::string S;
  std::cin >> S;
  if (S.size() < 1 || S.size() > 1e+5) {
    throw std::runtime_error("Input error!");
  }

  std::regex re(R"(^(dream|dreamer|erase|eraser)*$)");
  if (std::regex_match(S, re)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }

  return 0;
}
