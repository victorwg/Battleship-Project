# 1340-Group-Project
## Team Members
**1. Lam Yu Hang Julian (UID:3035687766) (Year 1 Engineering Student)**

**2. Wong Sai Yiu Victor (UID:3035687754) (Year 1 Engineering Student)**

## Game to be implemented (Battleship)
### Description
- Players given 5 battleships of different sizes to put on their board.
- Players take turns guessing opponent battleships by calling out the corresponding coordinates on the board.
- Try and sink all of the other player's battleships.

### Game Rules
#### General Rules
- Once the guessing begins, players may not move their ships.
- Board Size = 10 x 10
- Type of ships
1. Carrier (occupies spaces: 5)
2. Battleship (occupies spaces: 4)
3. Cruiser (occupies spaces: 3)
4. Submarine (occupies spaces: 3)
5. and Destroyer (occupies spaces: 2)

#### Placement of ship
- Ships can only be placed vertically or horizontally, diagonal placement is not allowed. 
- No part of a ship may hang off the edge of the board.  
- Ships may not overlap each other.  
- No ships may be placed on another ship. 

#### Playing the game
- Players take turns guessing by calling out the corresponding coordinates on the board. The opponent responds with "hit" or "miss" as appropriate.
- Players' board will be marked for record. **'O'** == hit, **'X'** == miss.

#### How to WIN
- When player sunk all opponent's ship == **VICTORY**.

### Features plan to implement
#### Game Mode 
- Player vs AI

### Functions plan to implement
- main(), the main body of the function.
- printBoard(), print the board of the user.
- play(), player turn to call coordinate.
- end(), check if all ships are sunk.
- num_moves(), shows number of moves needed to win.
