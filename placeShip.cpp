#include <iostream>
#include <cstdlib>
#include <string>
#include "placeShip.h"

using namespace std;

void placeShip(char ** ptr, string * pos) {

    //assign each point to an empty space for printing
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            ptr[row][col] = ' ';
        }
    }

    //srand(1); //delete this
    srand(time(NULL));

    int * ship = new int [5];
    ship[0] = 5; //Carrier
    ship[1] = 4; //Battleship
    ship[2] = 3; //Cruiser
    ship[3] = 3; //Submarine
    ship[4] = 2; //Destroyer

    for (int i = 0; i < 5; ++i) {
        int direction = rand() % 2;
        if (direction == 0) { //Vertical ship
            int ship_row = rand() % (10 - ship[i]);
            int ship_col = rand() % 10;
            //check if the ship overlaps each other
            for (int row = ship_row; row < ship_row + ship[i]; ++row) {
                if (ptr[row][ship_col] == '#') {
                    ship_row = rand() % (10 - ship[i]);
                    ship_col = rand() % 10;
                    row = ship_row - 1;
                }
            }
            //place ship
            for (int row = ship_row; row < ship_row + ship[i]; ++row) {
                ptr[row][ship_col] = '#';
                pos[i] = "V" + to_string(ship[i]) + to_string(row) + to_string(ship_col) + to_string(i); //store ship position
            }
        }
        else { //Horizontal ship
            int ship_row = rand() % 10;
            int ship_col = rand() % (10 - ship[i]);
            for (int col = ship_col; col < ship_col + ship[i]; ++col) {
                if (ptr[ship_row][col] == '#') {
                    ship_row = rand() % 10;
                    ship_col = rand() % (10 - ship[i]);
                    col = ship_col - 1;
                }
            }
            for (int col = ship_col; col < ship_col + ship[i]; ++col) {
                ptr[ship_row][col] = '#';
                pos[i] = "H" + to_string(ship[i]) + to_string(ship_row) + to_string(col) + to_string(i); //store ship position
            }
        }
    }

    delete [] ship;
    ship = NULL;
}
