#include "Board.h"

#include <array>
#include <vector>

#include "Player.h"
// #include <array>
#include <iostream>
using namespace std;

Board::Board() {
  board_.resize(size_);

  for (int i = 0; i < size_; ++i) {
    board_[i].resize(size_);
    // fill(board_[i].begin(), board_[i].end(), new int{0});
    for (int j = 0; j < size_; ++j) {
      board_[i][j] = new int{0};
    };
  }

  // for (int i = 0; i < size_; ++i) {
  //   for (int j = 0; j < size_; ++j) {
  //     board_[i][j] = new int{0};  //? {} vs ()
  //   };
  // };
};
Board::Board(int size) {
  this->size_ = size;

  board_.resize(size_);
  for (int i = 0; i < size_; ++i) {
    board_[i].resize(size_);
    for (int j = 0; j < size_; ++j) {
      board_[i][j] = new int{0};
    };
  }
};

Board::~Board() {
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      delete board_[i][j];
      board_[i][j] = nullptr;
    };
  };
};

int* Board::GetSquare(int row, int column) const {
  if (row < size_ && column < size_)
    return board_[row][column];
  else
    return nullptr;
};

int Board::GetRandomPos() const { return (rand() % size_) + 1; }

bool Board::MarkSquare(int row, int column, Player* player) {
  // todo set human var? efficiency of checking human twice
  if (!player->GetHuman()) {
    row = GetRandomPos();
    column = GetRandomPos();
  }

  --row;
  --column;
  // change to 1 base index
  // squarePtr == nullptr if out of range
  int* squarePtr = GetSquare(row, column);

  if (squarePtr != nullptr && *squarePtr == 0) {
    *board_[row][column] = player->GetId();
    ++totalMoves_;
    return true;
  };
  if (player->GetHuman()) cout << "Invalid space. Try again..." << endl;
  return false;
};

std::ostream& operator<<(std::ostream& out, const Board& board) {
  // out << "  1  2  3" << endl;
  // out << "  -  -  -";
  for (int i = 0; i < board.GetSize(); ++i) {
    out << "\n" << i + 1 << "|";
    for (int j = 0; j < board.GetSize(); ++j) {
      out << *board.board_[i][j] << "  ";
    };
  };
  out << endl << endl;
  return out;
};

bool Board::CheckWin(Player* player) const {
  //* there are patterns...
  //* if any rows(full sub-vector)
  //* if any columns (first, second... all same)
  //* if first, second, third elem same
  //* if last, 2nd last, 3rd last...
  // Not possible to win yet
  if (totalMoves_ < (size_ * 2 - 1)) return false;

  // board full
  // else if (totalMoves_ == (size_ * size_)) {
  //   cout << "moves: " << totalMoves_ << " " << size_ * size_ << endl;

  //   return NULL;
  // }
  // todo change this to use the ptrs for memory efficiency
  int prev_row_int = 0;
  int prev_left_diag = 0;
  int prev_right_diag = 0;
  int true_size = size_ - 1;
  bool win = false;

  vector<int> prev_col_int(size_, 0);

  for (int i = 0; i < size_; ++i) {
    // cout << board[i] << endl;
    if (prev_row_int != 0) {
      cout << "full horizontal row: " << i << endl;
      win = true;
    };
    for (int j = 0; j < size_; ++j) {
      int cur = *GetSquare(i, j);
      // if(cur == 0) //? maybe just pass/break
      //? if cur == 0 does it negate the rest of this loop
      //! horizontal row
      if (j == 0) {
        prev_row_int = cur;  //* first in row
        // } else if (prev_row_int != cur || cur == 0) {
      } else if (prev_row_int != cur) {
        prev_row_int = 0;
      }  //* if true on next iteration of i
      // else
      //   prev_row_int = cur;
      //! columns
      if (i == 0 && cur != 0)
        prev_col_int[j] = cur;  //* set first row
      else if (prev_col_int[j] != 0 && prev_col_int[j] == cur)
        prev_col_int[j] = cur;
      else
        prev_col_int[j] = 0;
      //* check any columns all matching on last iteration
      if (i == true_size && prev_col_int[j] != 0) {
        cout << "full column: " << j + 1 << endl;
        win = true;
      }
      //! Left to Right Diag
      if (i == 0 && j == 0)  //* init first
        prev_left_diag = cur;
      else if (i == j && prev_left_diag != cur)
        prev_left_diag = 0;
      //? pull this out of loop? var will be 0 or not
      if (i == j && i == true_size && prev_left_diag != 0) {
        cout << "Left to Right diagonal" << endl;
        win = true;
      };
      //! Right to Left Diag
      if (i == (true_size - j) && j == true_size)  //* init first
        prev_right_diag = cur;
      else if ((i == (true_size - j)) && prev_right_diag != cur)
        prev_right_diag = 0;
      //? pull this out of loop? var will be 0 or not
      if (i == true_size && j == 0 && prev_right_diag != 0) {
        cout << "Right to Left diagonal" << endl;
        win = true;
      };
      if (win) {
        cout << player->GetName() << " wins!" << endl;
        player->SetWin();
        return true;
      }
    };
  };
  return false;
};
/*
//! row 1 win
if ((*board_[0][0] != 0) &&
    ((*board_[0][0] == *board_[0][1]) && (*board_[0][0] == *board_[0][2]))) {
  // return *board_[0][0];
  //! row2 win
} else if ((*board_[1][0] != 0) && ((*board_[1][0] == *board_[1][1]) &&
                                    (*board_[1][0] == *board_[1][2]))) {
  // return *board_[1][0];
}  //! row3 win
else if ((*board_[2][0] != 0) && ((*board_[2][0] == *board_[2][1]) &&
                                  (*board_[2][0] == *board_[2][2]))) {
  // return *board_[2][0];
}  //! col 1 win
else if ((*board_[0][0] != 0) && ((*board_[0][0] == *board_[1][0]) &&
                                  (*board_[0][0] == *board_[2][0]))) {
  // return *board_[0][0];
}  //! col 2 win
else if ((*board_[0][1] != 0) && ((*board_[0][1] == *board_[1][1]) &&
                                  (*board_[0][1] == *board_[2][1]))) {
  // return *board_[0][1];
}  //! col 3 win
else if ((*board_[0][2] != 0) && ((*board_[0][2] == *board_[1][2]) &&
                                  (*board_[0][2] == *board_[2][2]))) {
  // return *board_[0][2];
}  //! diag L->R
else if ((*board_[0][0] != 0) && ((*board_[0][0] == *board_[1][1]) &&
                                  (*board_[0][0] == *board_[2][2]))) {
  // return *board_[0][0];
}  //! diag R->L
else if ((*board_[0][2] != 0) && ((*board_[0][2] == *board_[1][1]) &&
                                  (*board_[0][2] == *board_[2][0]))) {
  // return *board_[0][2];
} else
  return false;

cout << player->GetName() << " wins!" << endl;
player->SetWin();
return true;
}
*/
