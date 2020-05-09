# 1340-Group-Project
## Team Members
**1. Lam Yu Hang Julian (UID:3035687766) (Year 1 Engineering Student)**

**2. Wong Sai Yiu Victor (UID:3035687754) (Year 1 Engineering Student)**

## Problem Statement
1. Hoping to recreated a classic random-based and text-based game battleship completely. 
2. Strengthen our coding skills with the use of various important concepts in C++. (Dynamic memory arrangement, File I/O)
3. Broaden our horizon in the world of coding, hoping to grasp more knowledge on how to code.
4. Fulfill one of our goals, creating a game that is playable.

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
- main(), The main body of the function. (Input required, integer '1' for new gameplay, '2' for loading saved game, '3' for rules, '4' for ending gameplay)
- placeShip(), Randomize ships position and place it in the board. (No input required)
- printBoard(), Print the board. (No input required)
- play(), Player turn to call coordinate. (Input required, X-coordinate(A-J) and Y-coordinate(1-10)) (Output will be described in commit comment)
- check_ship(), Check if all ships are sunk. (No input required) (Output will be described in commit comment)
- save_gameStatus(), File I/O for saving game status to "gamedata.txt" (Input required, "/save")
- load_gameStatus(), file I/O for loading game status from "gamedata.txt" (Input required, integer '2' in main function)
- inputXCoord, allow user to input x-coordinate for guessing. (No input required)
- inputYCoord, allow user to input y-coordinate for guessing. (No input required)

### Dynamic Memory Management
We use dynamic array for this game, a 2d array is used to initialize the battleship board. Another array is used to store the position of the ship. The dynamic arrays will be deleted upon ending of the game. Memory of the board will therefore be free up.

### File I/O
We allow players to save their status and load it when they start a new game.
