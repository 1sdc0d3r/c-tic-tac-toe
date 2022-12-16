add multiple bots

invalid inputs for all cin

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

board.cpp
Exception has occurred.
EXC_BAD_ACCESS (code=1, address=0x0)
if (\*squarePtr == 0) # no \

---

int number;

cout << "Enter an Integer: ";
cin >> number;

// User types any char or string of length < 100

// Because input stream is in a failed state, cin will be evaluated to false
while ( !cin )
{
cin.clear (); // Restore input stream to working state
cin.ignore ( 100 , '\n' ); // Get rid of any garbage that user might have entered
cout << "I said enter an integer, Dumbass. Try again: ";
cin >> number; // After cin is restored and any garbage in the stream has been cleared, store user input in number again
}

---
