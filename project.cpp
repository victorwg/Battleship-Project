#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int size;


void placeShip(char ** ptr) {
    //assign each point to an empty space for printing
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            ptr[row][col] = ' ';
        }
    }

    //seed input, for easier program checking
    cout << "Please enter a seed number: ";
    int seed;
    cin >> seed;
    srand(seed);

    int * ship = new int [5];
    ship[0] = 5; //Carrier
    ship[1] = 4; //Battleship
    ship[2] = 3; //Cruiser
    ship[3] = 3; //Submarine
    ship[4] = 2; //Destroyer

    for (int i = 0; i < 5; ++i) {
        int direction = rand() % 2;
        if (direction == 0) { //horizontal ship
            int ship_row = rand() % (size - ship[i]);
            int ship_col = rand() % size;
            //check if the ship overlaps each other
            for (int row = ship_row; row < ship_row + ship[i]; ++row) {
                if (ptr[row][ship_col] == '#') {
                    ship_row = rand() % (size - ship[i]);
                    ship_col = rand() % size;
                    row = ship_row - 1;
                }
            }
            //place ship
            for (int row = ship_row; row < ship_row + ship[i]; ++row) {
                ptr[row][ship_col] = '#';
            }
        }
        else { //vertical ship
            int ship_row = rand() % size;
            int ship_col = rand() % (size - ship[i]);
            for (int col = ship_col; col < ship_col + ship[i]; ++col) {
                if (ptr[ship_row][col] == '#') {
                    ship_row = rand() % size;
                    ship_col = rand() % (size - ship[i]);
                    col = ship_col - 1;
                }
            }
            for (int col = ship_col; col < ship_col + ship[i]; ++col) {
                ptr[ship_row][col] = '#';
            }
        }
    }

    delete [] ship;
    ship = NULL;
}


void printRuler(char ** ptr) {
    //internal use, print ruler for efficient coding
    for (int i = 0; i < (5 + 4*size); ++i) {
        cout << i%10;
    }
    cout << endl;
}


void printBoard(char ** ptr) {
    cout << endl;

    //print column mark
    cout << "     ";
    for (int col = 0; col < size; ++col) {
        char letter = 'A' + col;
        cout << ' ' << letter << "  ";
    }

    //print map with row mark
    cout << right << endl;
    for (int row = 0; row < size; ++row) {
        cout << "     --- --- --- --- --- --- --- --- --- --- " << endl;
        cout << ' ' << setw(2) << row+1 << ' ';
        for (int col = 0; col < size; ++col) {
            //hide the ships for guessing
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
}


void play(char ** ptr) {
    //wait for editing
}


int main() {
    size = 10;

    //an array of pointers to arrays
    char ** ptr = new char * [size];
    for(int row = 0; row < size; ++row) {
        ptr[row] = new char [size];
    }

    cout << endl;
    cout << "                     |" << endl;
    cout << "                     |" << endl;
    cout << "            |        |" << endl;
    cout << "          |-|-|      |" << endl;
    cout << "            |        |" << endl;
    cout << "            | {O}    |" << endl;
    cout << "            '--|     |" << endl;
    cout << "              .|]_   |" << endl;
    cout << "        _.-=.' |     |" << endl;
    cout << "       |    |  |]_   |" << endl;
    cout << "       |_.-='  |   __|__" << endl;
    cout << "        _.-='  |\\   /|\\" << endl;
    cout << "       |    |  |-'-'-'-'-." << endl;
    cout << "       |_.-='  '========='" << endl;
    cout << "            `   |     |" << endl;
    cout << "             `. |    / \\" << endl;
    cout << "               ||   /   \\____.--=''''==--.._" << endl;
    cout << "               ||_.'--=='    |__  __  __  _.'" << endl;
    cout << "               ||  |    |    |\\ ||  ||  || |                        ___" << endl;
    cout << "  ____         ||__|____|____| \\||__||__||_/    __________________/|   |" << endl;
    cout << " |    |______  |===.---. .---.========''''=-._ |     |     |     / |   |" << endl;
    cout << " |    ||     |\\| |||   | |   |      '===' ||  \\|_____|_____|____/__|___|" << endl;
    cout << " |-.._||_____|_\\___'---' '---'______....---===''======//=//////========|" << endl;
    cout << " |--------------\\------------------/-----------------//-//////---------/" << endl;
    cout << " |               \\                /                 // //////         /" << endl;
    cout << " |                \\______________/                 // //////         /" << endl;
    cout << " |                                        _____===//=//////=========/" << endl;
    cout << " |=================================================================/" << endl;
    cout << " '----------------------------------------------------------------`" << endl;
    cout << '\n' <<endl;

    cout << "************************************************************************" << endl;
    cout << "************************ Welcome to Battleship! ************************" << endl;
    cout << "************************************************************************" << endl;

    char choice = 0;
    while (choice != '3') {
        cout << endl;
        cout << "1: NEW GAME" << endl;
    	cout << "2: RESUME GAME" << endl;
        cout << "3: QUIT" << endl;
        cout << endl;
    	cout << "Please select: ";
        cin >> choice;
        if (choice == '1') {
            placeShip(ptr);
            printBoard(ptr);
            play(ptr);
            
        }
        else if (choice == '2') {
            //wait for editing (file I/O)
            exit(1);
        }
        else if (choice == '3') {
            cout << endl;
            cout << "Thanks for playing!" << endl;
            break;
        }
        else {
            cout << "Error. Please try again. " << endl;
        }
    }

    //delete 2D array
    for(int row = 0; row < size; ++row) {
        delete [] ptr[row];
        ptr[row] = NULL;
    }
    delete [] ptr;
    ptr = NULL;

    return 0;
}
