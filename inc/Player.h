
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using std::string;

class Player {
 private:
  static int cur_playerId;
  string* name_;
  double wins_{0};
  double games_played_{1};

  int player_id_;

 public:
  Player();
  Player(string name);
  ~Player() {
    delete name_;
    name_ = nullptr;
  };

  void SetName(string& name);
  string GetName() const;
  int GetId() const;
  void SetWin();
  double GetWins();
  void IncGamesPlayed();
  double GetGamesPlayed();

  // todo show stats
  //   friend& ostream operator<<();
};

#endif