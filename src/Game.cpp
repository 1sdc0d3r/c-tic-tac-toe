#include <iostream>

#include "Board.h"
#include "Player.h"

using namespace std;

int main() {
  bool playing = true;

  Board board;
  Player player1;
  Player player2;
  Player* cur_player = &player1;

  int row_in = 0;
  int column_in = 0;

  while (playing) {
    cout << '\n' << cur_player->GetName() << "'s turn." << endl;
    cout << board;
    cout << "Choose row: ";
    cin >> row_in;
    cout << "Choose column: ";
    cin >> column_in;

    if (board.MarkSquare(row_in, column_in, cur_player)) {
      // set cur_player to next player
      cur_player == & player1 ? cur_player = &player2 : cur_player = &player1;
    } else {
      cout << "Invalid space. Try again..." << endl;
      continue;
    }
    if (board.CheckWin()) {
      cout << cur_player->GetName() << " wins!" << endl;
      cur_player->SetWin();
      break;
    }
  }
  /*
    while (playing) {
      cout << "Enter player 1 name: ";
      //  cin >> name;
      //  player1.SetName(name)
      cout << "Enter player 2 name: ";
      // cin >> name;
      //  player2.SetName(name);
      //  cout << 'Continue playing?'
      playing = false;
    };
  */
  return 0;
}
