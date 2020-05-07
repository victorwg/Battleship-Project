# 1340-Group-Project
## Team Members
**1. Lam Yu Hang Julian (UID:3035687766) (Year 1 Engineering Student)**

**2. Wong Sai Yiu Victor (UID:3035687754) (Year 1 Engineering Student)**

## Game to be implemented (Battleship)
### Description
- Player take turn guessing AI battleships by calling out the corresponding coordinates on the board.
- Try and sink all of the battleships.

### Game Rules
#### General Rules
- Once the guessing begins, ships won't move.
- Board Size = 10 x 10
- Type of ships
1. Carrier (occupies spaces: 5)
2. Battleship (occupies spaces: 4)
3. Cruiser (occupies spaces: 3)
4. Submarine (occupies spaces: 3)
5. Destroyer (occupies spaces: 2)

#### Placement of ship
- Ships can only be placed vertically or horizontally, diagonal placement is not allowed. 
- No part of a ship may hang off the edge of the board.  
- Ships may not overlap each other.  
- No ships may be placed on another ship. 

#### Playing the game
- Player take turn guessing by calling out the corresponding coordinates on the board.
- Player's board will be marked for record. **'O'** == hit, **'X'** == miss.

#### How to WIN
- When player sunk all opponent's ship == **VICTORY**.

### Features plan to implement
#### Game Mode 
- Player vs AI

### Functions plan to implement
- main(), the main body of the function.
- placeShip(), randomize ships in the board. (No input required)
- printBoard(), print the board. 
- play(), player turn to call coordinate.
- end(), check if all ships are sunk.
- num_moves(), shows number of moves needed to win.
- gameStatus(), file I/O for saving game status.

### Dynamic Memory Management
We use dynamic array for this game, a 2d array is used to initialize the battleship board. Another array is used to store the position of the ship. The dynamic arrays will be deleted upon ending of the game. Memory of the board will therefore be free up.


### File I/O
We allow players to save their status and load it when they start a new game.
