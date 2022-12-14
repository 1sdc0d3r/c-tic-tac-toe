#include "Board.h"

#include "Player.h"

// #include <array>
#include <iostream>
using namespace std;

Board::Board() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      board_[i][j] = new int{0};  //? {} vs ()
    };
  };
};
// Board::Board(int columns, int rows) {
//   board_ = new int[columns][rows];
//   for (int i = 0; i < columns; ++i) {
//     for (int j = 0; j < rows; ++j) {
//       //   board_
//     };
//   };
// };
Board::~Board() {
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      delete board_[i][j];
      board_[i][j] = nullptr;
    };
  };
};

int* Board::GetSquare(int row, int column) const {
  return board_[row][column];
};

bool Board::CheckWin() const {
  //* there are patterns...
  // Not possible to win yet
  if (totalMoves_ < (size_ * 2 - 1)) return 0;

  /*
  int* cur_line[size_] = new[size_];
  int cur_player = 0;

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (*board_[i][j] != 0) {
        //   check from each space if remaining possibilities for win

      }
    };
  };*/

  //! row 1 win
  if ((*board_[0][0] != 0) &&
      ((*board_[0][0] == *board_[0][1]) && (*board_[0][0] == *board_[0][2]))) {
    // return *board_[0][0];
    return true;
    //! row2 win
  } else if ((*board_[1][0] != 0) && ((*board_[1][0] == *board_[1][1]) &&
                                      (*board_[1][0] == *board_[1][2]))) {
    // return *board_[1][0];
    return true;
  }  //! row3 win
  else if ((*board_[2][0] != 0) && ((*board_[2][0] == *board_[2][1]) &&
                                    (*board_[2][0] == *board_[2][2]))) {
    // return *board_[2][0];
    return true;
  }  //! col 1 win
  else if ((*board_[0][0] != 0) && ((*board_[0][0] == *board_[1][0]) &&
                                    (*board_[0][0] == *board_[2][0]))) {
    // return *board_[0][0];
    return true;
  }  //! col 2 win
  else if ((*board_[0][1] != 0) && ((*board_[0][1] == *board_[1][1]) &&
                                    (*board_[0][1] == *board_[2][1]))) {
    // return *board_[0][1];
    return true;
  }  //! col 3 win
  else if ((*board_[0][2] != 0) && ((*board_[0][2] == *board_[1][2]) &&
                                    (*board_[0][2] == *board_[2][2]))) {
    // return *board_[0][2];
    return true;
  }  //! diag L->R
  else if ((*board_[0][0] != 0) && ((*board_[0][0] == *board_[1][1]) &&
                                    (*board_[0][0] == *board_[2][2]))) {
    // return *board_[0][0];
    return true;
  }  //! diag R->L
  else if ((*board_[0][2] != 0) && ((*board_[0][2] == *board_[1][1]) &&
                                    (*board_[0][2] == *board_[2][0]))) {
    // return *board_[0][2];
    return true;
  } else
    return false;
};

bool Board::MarkSquare(int row, int column, Player* player) {
  //   cout << "Choose a square: ";
  if (*GetSquare(row, column) == 0) {
    *board_[row][column] = player->GetId();
    ++totalMoves_;
    return true;
  };
  return false;
}

std::ostream& operator<<(std::ostream& out, const Board& board) {
  for (int i = 0; i < 3; ++i) {
    out << "\n";
    for (int j = 0; j < 3; ++j) {
      out << *board.board_[i][j] << "  ";
    };
  };
  out << endl << endl;
  return out;
};
