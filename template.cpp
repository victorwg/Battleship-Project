#include <iostream>
#include <iomanip>

using namespace std;

int row, col;

void makeBoard(char ** ptr) {
    for (int r = 0; r < 10; ++r) {
        for (int c = 0; c < 10; ++c) {
            ptr[r][c] = ' ';
        }
    }
}

void printBoard(char ** ptr) {
    cout << endl;
    cout << "012345678901234567890123456789012345678901234" << endl;
    cout << "      A   B   C   D   E   F   G   H   I   J  " << endl;
    
    cout << right;
    for (int r = 0; r < 10; ++r) {
        cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
        cout << ' ' << setw(2) << r+1 << ' ';
        for (int c = 0; c < 10; ++c) {
            cout << "| " << ptr[r][c] << ' ';
        }
        cout << '|' << endl;
    }
    cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
}


int main() {
    row = 10, col = 10;

    //an array of pointers to arrays
    char ** ptr = new char * [row];
    for(int r = 0; r < row; ++r) {
        ptr[r] = new char [col];
    }

    makeBoard(ptr);

    cout << "Welcome to Battleship!" << endl;
    printBoard(ptr);

    return 0;
}
cout << "012345678901234567890123456789012345678901234" << endl;
cout << "      A   B   C   D   E   F   G   H   I   J  " << endl;
cout << "  1 |   |   |   |   |   |   |   |   |   |   |" << endl;
cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
cout << "  2 |   |   |   |   |   |   |   |   |   |   |" << endl;
cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
cout << "  3 |   |   |   |   |   |   |   |   |   |   |" << endl;
cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
cout << "  4 |   |   |   |   |   |   |   |   |   |   |" << endl;
cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
cout << "  5 |   |   |   |   |   |   |   |   |   |   |" << endl;
cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
cout << "  6 |   |   |   |   |   |   |   |   |   |   |" << endl;
cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
cout << "  7 |   |   |   |   |   |   |   |   |   |   |" << endl;
cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
cout << "  8 |   |   |   |   |   |   |   |   |   |   |" << endl;
cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
cout << "  9 |   |   |   |   |   |   |   |   |   |   |" << endl;
cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
cout << " 10 |   |   |   |   |   |   |   |   |   |   |" << endl;
