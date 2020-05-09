#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "load_gameStatus.h"
#include "printBoard.h"

using namespace std;

bool load_gameStatus(char ** ptr, string * pos, int & overall, int & size_of_array, int & count) {

    ifstream fin ("gamedata.txt"); //file input
    if (fin.fail()) {
        cout << "Error. gamedata.txt is not found.\n" << endl;
        return 0;
    }

    string line;
    count = 0;
    for (int row = 0; getline(fin, line) && row < 10; ++row) { //extract info by lines
        strcpy(ptr[row], line.c_str());
        for (int col = 0; col < 10; ++col) {
            if (ptr[row][col] == 'X' || ptr[row][col] == 'O') {
                ++count; //count the turns
            }
        }
    }

    bool * hit = new bool [5]; //store ships' status (hit or not)
    for (int i = 0; i < 5; ++i) {
        hit[i] = 1;
    }

    for (int i = 0; getline(fin, line); ++i) { //for function checkShip()
        pos[i] = line;
        size_of_array = i+1;
        hit[pos[i][4]-'0'] = 0;
    }
    overall = 5 - size_of_array;

    fin.close();

    printBoard(ptr, count);

    for (int i = 0; i < 5; ++i) { //print the infomation to remind player
        if (hit[i]) {
            if (i == 0)
              cout << "You have sunk enermy's Carrier!" << endl;
            else if (i == 1)
              cout << "You have sunk enermy's Battleship!" << endl;
            else if (i == 2)
              cout << "You have sunk enermy's Crusier!" << endl;
            else if (i == 3)
              cout << "You have sunk enermy's Submarine!" << endl;
            else if (i == 4)
              cout << "You have sunk enermy's Destroyer!" << endl;
        }
    }

    delete [] hit;
    hit = NULL;

    return 1;
}
