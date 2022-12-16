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
  srand(time(0));

  int row_in = 0;
  int column_in = 0;
  int players_in = 0;
  int bots_in = 0;
  int board_size = 3;
  // int total_players = 0; //todo maybe? DRY
  const static int kMax_total_players = 5;

  Board* board = new Board(board_size);

  cout << "Welcome to multiplayer tic-tac-toe!\nHow many players do you "
          "want?[max: "
       << kMax_total_players << "] ";

  if (!TESTING) cin >> players_in;

  if (players_in < kMax_total_players) {
    cout << "How many computer bots do you want?[max: "
         << kMax_total_players - players_in << "] ";
    if (!TESTING) cin >> bots_in;
  }

  if (TESTING) players_in = 2;

  // too many players or not enough
  if (players_in > kMax_total_players)
    players_in = kMax_total_players;
  else if (players_in < 1)
    players_in = 1;

  // too many bots or not enough
  if (players_in + bots_in > kMax_total_players)
    bots_in = kMax_total_players - players_in;
  else if (players_in == 1 && bots_in < 1)
    bots_in = 1;

  // vector<Player*> players(players_in == 1 ? 2 : players_in, nullptr);
  vector<Player*> players(players_in + bots_in, nullptr);

  //? why does this work below for loop and not above...
  // if (players_in == 1) {
  //   // players.resize(2);  // or use if statement for initialization
  //   players[1] = new Player("Jack Barry");
  // };

  string player_name = "";
  for (int i = 0; i < players_in + bots_in; ++i) {
    if (i < players_in) {
      cout << "\nPlayer " << i + 1 << " choose your name: ";
      if (!TESTING) cin >> player_name;

      players[i] = new Player(player_name);
    } else  // populate bots
      players[i] = new Player();
    //? players.push_back(new Player(player_name));
  };

  // if (players_in == 1) {
  // players.resize(2);  // or use if statement for initialization
  // };

  cout << endl;
  while (playing) {
    // Player* cur_player = *players.begin();
    //* set starting player randomly
    Player* cur_player = players[rand() % (players_in + bots_in)];

    while (true) {
      if (!TESTING) cout << *board;

      if (!TESTING) cout << '\n' << cur_player->GetName() << "'s turn." << endl;
      if (!TESTING) {
        // todo use cout row/column same as testing
        // cout << "players:" << players_in << " curPlayer: " << cur_player
        //      << " player[1] " << players[1] << " back: " << players.back()
        //      << endl;
        //! SINGLE PLAYER
        if (cur_player->GetHuman() == false) {
          row_in = (rand() % board->GetSize()) + 1;
          column_in = (rand() % board->GetSize()) + 1;
          cout << cur_player->GetName() << " chooses row: " << row_in
               << " col: " << column_in << endl;
        } else {
          cout << "Choose row: ";
          cin >> row_in;
          cout << "Choose column: ";
          cin >> column_in;
        };
      };
      if (TESTING) {
        row_in = (rand() % board->GetSize()) + 1;
        column_in = (rand() % board->GetSize()) + 1;
        // cout << "row: " << row_in << " col: " << column_in << endl;
      }
      if (board->MarkSquare(row_in, column_in, cur_player) == false) {
        if (!TESTING) cout << "Invalid space. Try again..." << endl;
        continue;
      };
      // if (!TESTING)
      // cout << *board;
      if (board->CheckWin(cur_player)) {
        // if (TESTING) cout << *board;
        // if (TESTING) cout << "row: " << row_in << " col: " << column_in <<
        // endl;
        break;
      } else if (board->GetMoves() == (board->GetSize() * board->GetSize())) {
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
    cout << *board;
    //! print stats and inc game played
    for (Player* player : players) {
      cout << *player;
      player->IncGamesPlayed();
    }
    // or use q to quit...
    if (TESTING and ++test_round == num_of_test_rounds) break;

    if (!TESTING) {
      std::string play_again = "n";
      cout << "Play again? (n or y): ";
      cin >> play_again;

      if (play_again == "n") {
        cout << endl;
        break;
      };
    };

    delete board;
    board = new Board;
    cout << endl;
  }
  return 0;
}
