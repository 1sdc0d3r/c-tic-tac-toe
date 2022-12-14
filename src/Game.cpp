#include <cstring>
#include <iostream>

#include "Board.h"
#include "Player.h"

using namespace std;

int main() {
  bool playing = true;
  bool testing = true;
  int test_round{0};

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
      if (!testing) {
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
        cout << cur_player->GetName() << " wins!" << endl;
        cur_player->SetWin();
        break;
      } else if (board->GetMoves() == (board->GetSize() * board->GetSize())) {
        cout << *board;
        cout << "It's a tie!" << endl;
        break;
      };
      // set cur_player to next player
      cur_player == & player1 ? cur_player = &player2 : cur_player = &player1;
    }
    cout << "Play again? (n or y): ";
    std::string play_again = "n";
    if (testing and ++test_round < 20) {
      play_again = "y";
    } else
      play_again = "n";
    if (!testing) cin >> play_again;

    if (play_again == "n") {
      cout << player1;
      cout << player2;
      break;
    };

    delete board;
    board = new Board;
  }
  return 0;
}
