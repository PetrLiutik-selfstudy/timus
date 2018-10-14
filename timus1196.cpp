#include <iostream>
#include <map>
#include <algorithm>

int main()
{
  int n;
  std::cin >> n;

  std::map<int, int> dates;
  for(int i = 0; i < n; ++i)
  {
    int date;
    std::cin >> date;
    dates[date] = 0;
  }

  int m;
  std::cin >> m;

  for(int i = 0; i < m; ++i)
  {
    int date;
    std::cin >> date;

    auto it = dates.find(date);
    if(it != dates.end())
      it->second++;
  }

  int sum = 0;
  for(auto it : dates)
    sum += it.second;

  std::cout << sum << std::endl;

  return 0;
}
