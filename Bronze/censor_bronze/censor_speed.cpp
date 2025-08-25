#include <iostream>
#include <string>
#include <array>

std::array<std::string, 2> GetInput () {
  std::string original, censor_content;
  std::getline (std::cin, original) ;
  std::getline (std::cin, censor_content) ;
  return {original, censor_content};
}

void Censor () {
  auto inp = GetInput () ;
  const std::string& target = inp[1];
    std::string result;
    for (char c : inp[0]) {
      result.push_back(c);
      // Check if the end of result matches the target
      if (result.size() >= target.size() &&
        result.compare(result.size() - target.size(), target.size(), target) == 0) {
        // Remove the matched substring
        result.erase(result.size() - target.size(), target.size());
    }
  }
  std::cout << result << std::endl;
}

int main () {
  Censor () ;
  return 0;
}

