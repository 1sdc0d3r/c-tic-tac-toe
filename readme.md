add single player functonality

set max board size -- in h file
maybe game class/struct to handle vars
memory issue with non testing -- every other causes loop

Player.cpp
Exception has occurred.
EXC*BAD_ACCESS (code=1, address=0x1007ffff8)
string Player::GetName() const { return name*; };

1|2 1 2
2|2 2 1
3|1 1 1
It's a tie!

check"Right to Left diagonal"

board.cpp
Exception has occurred.
EXC_BAD_ACCESS (code=1, address=0x0)
if (\*squarePtr == 0) # no \

mark square not working every turn for 'ai' on single player mode
