#include "Player.h"

#include <iomanip>
#include <ostream>
#include <string>
using std::string;

int Player::cur_playerId = 1;

Player::Player() : player_id_(cur_playerId) {
  string name = "Player ";
  name += std::to_string(player_id_);

  SetName(name);
  ++cur_playerId;
};
Player::Player(string name) : player_id_(cur_playerId) {
  SetName(name);
  ++cur_playerId;
};

void Player::SetName(string& name) { name_ = string(name); };

string Player::GetName() const { return name_; };
int Player::GetId() const { return player_id_; };

void Player::SetWin() { ++wins_; };
double Player::GetWins() { return wins_; };
void Player::IncGamesPlayed() { ++games_played_; };
double Player::GetGamesPlayed() { return games_played_; };

// todo when 100% it shows 1e+0
std::ostream& operator<<(std::ostream& out, const Player& player) {
  out << std::setprecision(2);
  double win_ratio = (player.wins_ / player.games_played_) * 100;
  if (player.games_played_ == 0) win_ratio = 0;

  out << player.name_ << " has won " << player.wins_ << " out of "
      << player.games_played_ << " games. " << win_ratio << "% won"
      << std::endl;

  return out;
};
