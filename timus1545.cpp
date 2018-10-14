#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  // Read dictionary length.
  int dict_len = 0;
  std::cin >> dict_len;

  std::vector<std::string> dict;
  dict.reserve(dict_len);

  std::string hier;
  // Dummy read.
  std::getline(std::cin, hier);

  // Read hieroglyphs.
  for(int i = 0; i < dict_len; ++i) {
    std::getline(std::cin, hier);
    dict.emplace_back(hier);
  }

  // Read first char.
  char ch;
  std::cin.get(ch);

  // Sort dictionary.
  std::sort(dict.begin(), dict.end());

  // Find all hieroglyphs started from char.
  std::for_each(dict.begin(), dict.end(), [&ch](const std::string& hier){
    if(!hier.empty()) {
      if(hier[0] == ch)
        std::cout << hier << std::endl;
    }
  });

  return 0;
}
