#include <iostream>
#include <string>
#include <array>

using namespace std;

array<string, 2> GetInput() {
  string original, censor_content;
  getline (cin, original);
  getline (cin, censor_content);
  return {original, censor_content};
}

void Censor() {
  auto inp = GetInput();
  const string target = inp[1];
  string result;
  for (char c : inp[0]) {
    result.push_back(c);
    // Check if the end of result matches the target
    if (result.size() >= target.size() &&
      result.compare(result.size() - target.size(), target.size(), target) == 0) {
      // Remove the matched substring
      result.erase(result.size() - target.size(), target.size());
    } 
  }
  cout << result << endl;
}

int main() {
  Censor() ;
  return 0;
}

