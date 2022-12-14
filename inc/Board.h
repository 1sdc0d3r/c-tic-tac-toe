#ifndef BOARD_H
#define BOARD_H
#include <ostream>

#include "Player.h"

struct col_row {
  int column;
  int row;
};

class Board {
 private:
  int* board_[3][3];
  //   int** board_ = NULL;
  int size_ = 3;  // ? keep square
  int totalMoves_{0};

 public:
  Board();
  // todo dynamically allocate board for custom size
  //   Board(int columns, int rows);
  ~Board();

  int* GetSquare(int row, int column) const;
  bool CheckWin() const;
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
#endif
