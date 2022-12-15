// only defined if Valgrind running on github actions
#ifndef TESTING
#define TESTING false
#endif

#include <time.h>

#include <cstring>
#include <iostream>
// #include <optional>

#include "Board.h"
#include "Player.h"

using namespace std;

int main() {
  bool playing = true;
  int test_round{0};
  int num_of_test_rounds{5};

  // Use current time as seed for TESTING random generator
  if (TESTING) srand(time(0));

  Board* board = new Board;
  Player player1;
  Player player2("Jack Barry");
  Player* cur_player = &player1;

  int row_in = 0;
  int column_in = 0;

  while (playing) {
    cout << endl;
    cout << player1;
    cout << player2;
    player1.IncGamesPlayed();
    player2.IncGamesPlayed();

    while (true) {
      cout << *board;
      cout << '\n' << cur_player->GetName() << "'s turn." << endl;
      if (!TESTING) {
        cout << "Choose row: ";
        cin >> row_in;
        cout << "Choose column: ";
        cin >> column_in;
      } else {
        row_in = rand() % board->GetSize();
        column_in = rand() % board->GetSize();
        row_in++;
        column_in++;
        cout << "row: " << row_in << " col: " << column_in << endl;
      }
      if (board->MarkSquare(row_in, column_in, cur_player) == false) {
        cout << "Invalid space. Try again..." << endl;
        continue;
      }
      if (board->CheckWin(cur_player)) {
        cout << *board;
        // cout << cur_player->GetName() << " wins!" << endl;
        // cur_player->SetWin();
        break;
      } else if (board->GetMoves() == (board->GetSize() * board->GetSize())) {
        cout << *board;
        cout << "It's a tie!" << endl;
        break;
      };
      // set cur_player to next player
      cur_player == & player1 ? cur_player = &player2 : cur_player = &player1;
    }
    std::string play_again = "n";
    if (TESTING and ++test_round < num_of_test_rounds) {
      play_again = "y";
    } else
      play_again = "n";
    if (!TESTING) {
      cout << "Play again? (n or y): ";
      cin >> play_again;
    };

    if (play_again == "n") {
      cout << endl;
      cout << player1;
      cout << player2;
      cout << endl;
      break;
    };

    delete board;
    board = new Board;
  }
  return 0;
}
