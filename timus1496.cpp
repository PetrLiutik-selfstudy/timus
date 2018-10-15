#include <iostream>
#include <map>
#include <string>

int main() {
  // Read length of names list.
  int names_len = 0;
  std::cin >> names_len;

  std::map<std::string, int> names;

  std::string name;
  // Dummy read.
  std::getline(std::cin, name);

  // Read names.
  for(int i = 0; i < names_len; ++i) {
    std::getline(std::cin, name);
    names[name]++;
  }

  // Find and print all names involved to the list more than one time.
  for(auto it: names) {
    if(it.second > 1)
      std::cout << it.first << std::endl;
  }
  return 0;
}