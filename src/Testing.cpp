
#include <time.h>

#include <cstring>
#include <iostream>
#include <string>
// #include <optional>

#include "Board.h"
#include "Player.h"

using namespace std;

int main() {
  bool playing = false5;
  int test_round{0};
  int num_of_test_rounds{15};

  // Use current time as seed for TESTING random generator
  srand(time(0));

  Board* board = new Board(3);

  int row_in = 0;
  int column_in = 0;
  int players_in = 1;
  cout << "------------board wins-----------" << endl;
  vector<Player*> players(players_in, nullptr);

  players[0] = new Player("Player 1");

  while (playing) {
    // cout << "moves: " << board->GetMoves() << endl;
    //!   if (board->GetMoves() == 0) {
    //!     cout << "move: " << 0 << endl;
    //!     row_in = 1;
    //!     column_in = 2;
    //!   } else if (board->GetMoves() == 1) {
    //!     cout << "move: " << 1 << endl;
    //!     row_in = 1;
    //!     column_in = 1;
    //!   } else if (board->GetMoves() == 2) {
    //!     cout << "move: " << 2 << endl;
    //!     row_in = 2;
    //!     column_in = 0;
    //!   }
    if (board->MarkSquare(row_in, column_in, cur_player) == false) {
      if (!TESTING) cout << "Invalid space. Try again..." << endl;
      continue;
    };
    // if (!TESTING)
    // cout << *board;
    if (board->CheckWin(cur_player)) {
      // if (TESTING) cout << *board;
      if (TESTING) cout << "row: " << row_in << " col: " << column_in << endl;
      break;
    } else if (board->GetMoves() == (board->GetSize() * board->GetSize())) {
      if (TESTING) cout << *board;
      cout << "It's a tie!" << endl;
      break;
    };
    // set cur_player to next player
    // next gets next player in vector
    if (cur_player == players.back())
      cur_player = *players.begin();
    else
      cur_player = next(cur_player, 1);
  }

  delete board;
  board = new Board;
}
return 0;
