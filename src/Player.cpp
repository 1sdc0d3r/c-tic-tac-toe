#include "Player.h"

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

void Player::SetName(string& name) { name_ = new string(name); };

string Player::GetName() const { return *name_; };
int Player::GetId() const { return player_id_; };

void Player::SetWin() { ++wins_; };
double Player::GetWins() { return wins_; };
void Player::IncGamesPlayed() { ++games_played_; };
double Player::GetGamesPlayed() { return games_played_; };
