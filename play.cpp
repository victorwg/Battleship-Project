#include <iostream>
#include <string>
#include "play.h"
#include "input.h"
#include "printBoard.h"
#include "checkShip.h"

using namespace std;

void play(char ** ptr, string * pos, int & overall, int & size_of_array, int & count) {

    while (overall != 5) {//ships that are hitted
        count++;

        cout << "Soilder, it's time!" << endl;
        cout << "Sink all the enemy's ships!" << endl;
        cout << endl;

        int * step = new int [2]; //store coordinate
        step[0] = -1;
        input(ptr, step, pos, size_of_array);

        if (step[0] < 0) {
            break;
        }

        while (ptr[step[0]][step[1]] == 'X' || ptr[step[0]][step[1]] == 'O') {//check if it's repeated
            cout << "You have attacked that point already!" << endl;
            cout << endl;
            input(ptr, step, pos, size_of_array); //input again
        }

        if (step[0] < 0) {
            break;
        }

        bool tf; //for printing info
        if (ptr[step[0]][step[1]] != '#') {//miss
            ptr[step[0]][step[1]] = 'X';
            delete [] step;
            step = NULL;
            tf = 0;
        }
        else {//hit
            ptr[step[0]][step[1]] = 'O';
            delete [] step;
            step = NULL;
            tf = 1;
        }

        printBoard(ptr, count);

        if (tf) {
            cout << "Enemy's ship hit!" << endl;
            cout << "Keep going soldier!" << endl;
        }
        else {
            cout << "Enemy's ship missed!" << endl;
            cout << "Don't give up soldier!" << endl;
        }

        checkShip(ptr,pos,overall,size_of_array); //check ship status
    }

    if (overall == 5) {//victory
        cout << endl;
        cout << "Good Job, soldier!" << endl;
        cout << "You sunk all enemy's ships!" << endl;
        cout << "You used " + to_string(count) + " turns to win! Well done!" << endl;
    }

    cout << endl;
    cout << "*************************** Battleship *********************************" << endl; //breakline
    cout << endl;
}
