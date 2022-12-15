// #ifndef BOARD_H
// #define BOARD_H
#pragma once
#include <ostream>
#include <vector>

#include "Player.h"

struct col_row {
  int column;
  int row;
};
using std::vector;
class Board {
 private:
  // int* board_[3][3];
  int size_ = 3;  //* keep square
  int totalMoves_{0};

 public:
  vector<vector<int*>> board_;
  Board();
  // todo dynamically allocate board for custom size
  Board(int size);
  ~Board();

  int* GetSquare(int row, int column) const;
  bool CheckWin(Player* player) const;
  inline int GetSize() const { return size_; }
  inline int GetMoves() const { return totalMoves_; }

  /**
   * @brief
   *
   * @param column
   * @param row
   * @param player
   * @return int 0 if not valid space 1 if space is open
   */
  bool MarkSquare(int row, int column, Player* player);
  friend std::ostream& operator<<(std::ostream& out, const Board& board);
};
// #endif
