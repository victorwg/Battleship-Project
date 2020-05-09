#include <iostream>
#include "placeShip.h"
#include "printBoard.h"
#include "load_gameStatus.h"
#include "play.h"

using namespace std;

int main() {

    //an array of pointers to arrays
    char ** ptr = new char * [10];
    for(int row = 0; row < 10; ++row) {
        ptr[row] = new char [10];
    }

    //an array to store position of ships
    string * pos = new string [5];
    for (int i = 0; i < 5 ; ++i) {
      pos[i] = ' ';
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
    cout << '\n' << endl;

    cout << "************************************************************************" << endl;
    cout << "************************ Welcome to Battleship! ************************" << endl;
    cout << "************************************************************************" << endl;
    cout << '\n' << endl;

    char choice;
    int count, overall, size_of_array;
    while (choice != '4') {
        //print menu
        cout << "1: NEW GAME" << endl;
    	cout << "2: RESUME GAME" << endl;
        cout << "3: HOW TO PLAY" << endl;
        cout << "4: QUIT" << endl;
        cout << endl;
    	cout << "Please select: ";
        cin >> choice;
        cout << endl;

        if (choice == '1') {
            choice = 0;
            count = 0, overall = 0, size_of_array = 5;
            placeShip(ptr,pos);
            printBoard(ptr, count);
            play(ptr,pos,overall,size_of_array,count);
        }
        else if (choice == '2') {
            load_gameStatus(ptr,pos,overall,size_of_array,count);
            play(ptr,pos,overall,size_of_array,count);
        }
        else if (choice == '3') { //print rules
            cout << "*************************** General Rules ******************************" << endl;
            cout << "1. Once the guessing begins, ships won't move.                          " << endl;
            cout << "2. 5 Types of ship in Battleship!                                       " << endl;
            cout << "2.1 Carrier (occupies spaces: 5)                                        " << endl;
            cout << "2.2 Battleship (occupies spaces: 4)                                     " << endl;
            cout << "2.3 Cruiser (occupies spaces: 3)                                        " << endl;
            cout << "2.4 Submarine (occupies spaces: 3)                                      " << endl;
            cout << "2.5 Destroyer (occupies spaces: 2)                                      " << endl;
            cout << "3. Ships can only be placed vertically or horizontally.                 " << endl;
            cout << "4. No part of a ship may hang off the edge of the board.                " << endl;
            cout << "5. Ships may not overlap each other.                                    " << endl;
            cout << "6. No ships may be placed on another ship.                              " << endl;
            cout << "************************************************************************" << endl;
            cout << '\n' << endl;
            cout << "*************************** How to play ********************************" << endl;
            cout << "Player take turn calling out the corresponding coordinates on the board." << endl;
            cout << "Players' board will be marked for record. 'O' == hit, 'X' == miss.      " << endl;
            cout << "When player sunk all opponent's ship == VICTORY.                        " << endl;
            cout << "************************************************************************" << endl;
            cout << endl;
            cout << "*************************** Battleship *********************************" << endl;
            cout << endl;
        }
        else if (choice == '4') {
            cout << "Thanks for playing!" << endl;
            cout << "            ." << endl;
            cout << "           \":\"" << endl;
            cout << "         ___:____     |\"\\/\"|" << endl;
            cout << "       ,'        `.    \\  /" << endl;
            cout << "       |  O        \\___/  |" << endl;
            cout << "     ~^~^~^~^~^~^~^~^~^~^~^~^~" << endl;
            cout << endl;
            break;
        }
        else { //invalid input
            cout << "Error. Please try again. " << endl;
        }
    }

    //delete 2D array
    for(int row = 0; row < 10; ++row) {
        delete [] ptr[row];
        ptr[row] = NULL;
    }
    delete [] ptr;
    ptr = NULL;

    delete [] pos;
    pos = NULL;

    return 0;
}
