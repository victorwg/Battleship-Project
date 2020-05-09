#include <iostream>
#include <fstream>
#include "save_gameStatus.h"

using namespace std;

void save_gameStatus(char ** ptr, string * pos, int & size_of_array) {

    ofstream fout ("gamedata.txt"); //file output
    if (fout.fail()) {
        exit(1);
    }

    for (int row = 0; row < 10; ++row) { //print the game map
        for (int col = 0; col < 10; ++col) {
            fout << ptr[row][col];
        }
        fout << endl;
    }
    fout << endl;
    for (int i = 0; i < size_of_array; ++i) { //print ship orientation
      fout << pos[i] << endl;
    }

    fout.close();

    cout << endl;
    cout << "Successful!" << endl;
    cout << "Game saved as gamedata.txt" << endl;
}
