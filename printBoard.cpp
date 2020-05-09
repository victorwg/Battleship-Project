#include <iostream>
#include <iomanip>
#include "printBoard.h"

using namespace std;

void printBoard(char ** ptr, int count) {

    cout << endl;

    //print column mark
    cout << "     ";
    for (int col = 0; col < 10; ++col) {
        char letter = 'A' + col;
        cout << ' ' << letter << "  ";
    }

    //print map with row mark
    cout << right << endl;
    for (int row = 0; row < 10; ++row) {
        cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
        cout << ' ' << setw(2) << row+1 << ' ';
        for (int col = 0; col < 10; ++col) {
            //hide the ships for guessing
            //cout << "| " << ptr[row][col] << ' '; //delete this
            if (ptr[row][col] == 'O' || ptr[row][col] == 'X') {
                cout << "| " << ptr[row][col] << ' ';
            }
            else {
                cout << "|   ";
            }
        }
        cout << '|' << endl;
    }
    cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
    cout << endl;

    cout << "                                   "; //a tidy printing
    if (count < 10) {
        cout << "  ";
    }
    else if (count < 100) {
        cout << ' ';
    }
    cout << "Turns: " << count << endl;
    cout << endl;
}
