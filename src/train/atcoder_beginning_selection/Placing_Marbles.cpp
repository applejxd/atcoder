#include <iostream>
#include <array>

int main () {
  std::string input{""};
  std::cin >> input;
  if (input.size() != 3) {
    throw std::runtime_error("Input Error: The size is not 3.");
  }

  int ans{0};
  for (const auto& character : input) {
    if (character == '1') {
      ++ans;
    } else if (character != '0') {
      throw std::runtime_error("Input Error: Input is unexpected character.");
    }
  }

  std::cout << ans << std::endl;

  return 0;
}