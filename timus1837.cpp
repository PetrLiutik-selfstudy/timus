#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>

// Team size.
static constexpr int team_size = 3;

// Player structure.
struct Player {
  int is_no; // Player's Isenbaev number.
  std::vector<int> teams; // Teams where player takes part.
};

int main()
{
  // Read number of teams.
  int n;
  std::cin >> n;

  std::map<std::string, Player> players;

  // Dummy read.
  std::string dummy;
  std::getline(std::cin, dummy);

  for(int i = 0; i < n; ++i) {
    std::string name;
    for(int j = 0; j < team_size; ++j) {
      // Read players names.
      char delim = (j == (team_size - 1)) ? '\n' : ' ';
      std::getline(std::cin, name, delim);

      // Set preliminary player's Isenbaev number.
      players[name].is_no = (name == "Isenbaev") ? 0 : INT_MAX;
      // Add teams where player takes part.
      players[name].teams.emplace_back(i);
    }
  }

  for(int i = 0; i < n; ++i) {
    for(const auto& player: players) {
      if(player.second.is_no < INT_MAX) // Search for players with known Isenbaev number.
        for(const auto& team: player.second.teams)
          for(auto& other_player: players) // Search for teammates.
            for(const auto& other_team: other_player.second.teams)
              if(other_team == team)
                if(player.second.is_no < other_player.second.is_no) // Set new Isenbaev number if teammate has worse one.
                  other_player.second.is_no = player.second.is_no + 1;
    }
  }

  // Print players' names and their Isenbaev numbers.
  for(auto it: players) {
    std::cout << it.first << " ";
    if(it.second.is_no == INT_MAX)
      std::cout << "undefined" << std::endl;
    else
      std::cout << it.second.is_no << std::endl;
  }

  return 0;
}
