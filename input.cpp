#include <iostream>
#include <string>
#include "input.h"
#include "save_gameStatus.h"

using namespace std;

void input(char ** ptr, int * step, string * pos, int & size_of_array) {

    string cmd;
    bool error = 1; //a bool variable for looping

    while (error) { //input again when there is invalid input
        error = 0;
        cout << "Enter a coordinate (e.g. A10) to attack" << endl;
        cout << "Enter \"/save\" to save game status and back to menu" << endl;
        cout << "Your command: ";
        cin >> cmd;
        if (cmd == "/save") { //saving game status
            save_gameStatus(ptr, pos, size_of_array);
        }
        else if (cmd.length() == 2) {
            if (cmd[0] != 'A' && cmd[0] != 'B' && cmd[0] != 'C' && cmd[0] != 'D' && cmd[0] != 'E' && cmd[0] != 'F' && cmd[0] != 'G' && cmd[0] != 'H' && cmd[0] != 'I' && cmd[0] != 'J' ||
            cmd[1] != '1' && cmd[1] != '2' && cmd[1] != '3' && cmd[1] != '4' && cmd[1] != '5' && cmd[1] != '6' && cmd[1] != '7' && cmd[1] != '8' && cmd[1] != '9') {
                cout << "Sorry invalid option!\n" << endl;
                error = 1;
            }
        }
        else if (cmd.length() == 3) {
            if (cmd[0] != 'A' && cmd[0] != 'B' && cmd[0] != 'C' && cmd[0] != 'D' && cmd[0] != 'E' && cmd[0] != 'F' && cmd[0] != 'G' && cmd[0] != 'H' && cmd[0] != 'I' && cmd[0] != 'J' ||
            cmd[1] != '1' || cmd[2] != '0') {
                cout << "Sorry invalid option!\n" << endl;
                error = 1;
            }
        }
        else { //invalid input
            cout << "Sorry invalid option!\n" << endl;
            error = 1;
        }
    }

    if (cmd[0] == 'A') //turning the character to integer for calculation
        step[1] = 0;
    else if (cmd[0] == 'B')
        step[1] = 1;
    else if (cmd[0] == 'C')
        step[1] = 2;
    else if (cmd[0] == 'D')
        step[1] = 3;
    else if (cmd[0] == 'E')
        step[1] = 4;
    else if (cmd[0] == 'F')
        step[1] = 5;
    else if (cmd[0] == 'G')
        step[1] = 6;
    else if (cmd[0] == 'H')
        step[1] = 7;
    else if (cmd[0] == 'I')
        step[1] = 8;
    else if (cmd[0] == 'J')
        step[1] = 9;

    if (cmd[2] == '0' && cmd[1] == '1') //turning the character to integer for calculation
        step[0] = 9;
    else if (cmd[1] == '1')
        step[0] = 0;
    else if (cmd[1] == '2')
        step[0] = 1;
    else if (cmd[1] == '3')
        step[0] = 2;
    else if (cmd[1] == '4')
        step[0] = 3;
    else if (cmd[1] == '5')
        step[0] = 4;
    else if (cmd[1] == '6')
        step[0] = 5;
    else if (cmd[1] == '7')
        step[0] = 6;
    else if (cmd[1] == '8')
        step[0] = 7;
    else if (cmd[1] == '9')
        step[0] = 8;
    //return the coordinate in dynamic array by pass by reference
}
