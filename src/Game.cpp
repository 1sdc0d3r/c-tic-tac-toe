// only defined if Valgrind running on github actions
#ifndef TESTING
#define TESTING false
#endif

#include <time.h>

#include <cstring>
#include <iostream>
#include <string>
// #include <optional>

#include "Board.h"
#include "Player.h"

using namespace std;

int main() {
  bool playing = true;
  int test_round{0};
  int num_of_test_rounds{15};

  // Use current time as seed for TESTING random generator
  if (TESTING) srand(time(0));

  Board* board = new Board(3);

  int row_in = 0;
  int column_in = 0;
  int players_in = 0;

  cout << "Welcome to multiplayer tic-tac-toe!\nHow many players do you "
          "want?[max: 5] ";

  if (!TESTING) cin >> players_in;

  if (TESTING) players_in = 2;

  if (players_in > 5)
    players_in = 5;
  else if (players_in < 1)
    players_in = 1;

  vector<Player*> players(players_in == 1 ? 2 : players_in);

  //? why does this work below for loop and not above...
  // if (players_in == 1) {
  //   // players.resize(2);  // or use if statement for initialization
  //   players[1] = new Player("Jack Barry");
  // };

  string player_name = "Jack Barry ";
  for (int i = 0; i < players_in; ++i) {
    cout << "\nPlayer " << i + 1 << " choose your name: ";
    if (!TESTING) cin >> player_name;
    if (!TESTING) player_name = "me";
    if (TESTING) player_name += to_string(i);

    players[i] = new Player(player_name);
    //? players.push_back(new Player(player_name));
  };

  if (players_in == 1) {
    // players.resize(2);  // or use if statement for initialization
    players[1] = new Player("Jack Barry");
  };

  while (playing) {
    cout << endl;
    Player* cur_player = *players.begin();
    cout << "cur: " << cur_player->GetId() << endl;
    ;
    for (Player* player : players) {
      cout << *player;
    }

    while (true) {
      if (!TESTING) cout << *board;

      if (!TESTING) cout << '\n' << cur_player->GetName() << "'s turn." << endl;
      if (!TESTING) {
        // todo use cout row/column same as testing
        cout << "players:" << players_in << " curPlayer: " << cur_player
             << " player[1] " << players[1] << " back: " << players.back()
             << endl;

        if (players_in == 1 && cur_player == players[1]) {
          cout << "Choose row: ";
          row_in = rand() % board->GetSize();
          cout << row_in << endl;

          cout << "Choose column: ";
          column_in = rand() % board->GetSize();
          cout << column_in << endl;
        } else {
          cout << "Choose row: ";
          cin >> row_in;
          cout << "Choose column: ";
          cin >> column_in;
        };
      } else {
        row_in = rand() % board->GetSize();
        column_in = rand() % board->GetSize();
        // cout << "moves: " << board->GetMoves() << endl;
        if (board->GetMoves() == 0) {
          cout << "move: " << 0 << endl;
          row_in = 0;
          column_in = 2;
        } else if (board->GetMoves() == 1) {
          cout << "move: " << 1 << endl;
          row_in = 1;
          column_in = 1;
        } else if (board->GetMoves() == 2) {
          cout << "move: " << 2 << endl;
          row_in = 2;
          column_in = 0;
        }
        cout << "rand: " << row_in << " " << column_in << endl;
        row_in++;
        column_in++;
        if (!TESTING)
          cout << "row: " << row_in << " col: " << column_in << endl;
      }
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

      // cur_player == & player1 ? cur_player = &player2 : cur_player =
      // &player1;
    }
    // print stats and inc game played
    for (Player* player : players) {
      cout << *player;
      player->IncGamesPlayed();
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
      break;
    };

    delete board;
    board = new Board;
  }
  return 0;
}
