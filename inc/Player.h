
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using std::string;

class Player {
 private:
  static int cur_playerId;
  string name_ = "";
  double wins_{0};
  double games_played_{0};
  bool human_ = true;

  int player_id_;

 public:
  Player();
  Player(string name);
  ~Player(){
      // delete name_;
      // name_ = nullptr;
  };

  void SetName(string& name);
  string GetName() const;
  int GetId() const;
  void SetWin();
  double GetWins();
  void IncGamesPlayed();
  double GetGamesPlayed();
  bool GetHuman() { return human_; }

  // show stats
  friend std::ostream& operator<<(std::ostream& out, const Player& player);
};

#endif
