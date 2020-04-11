#include <iostream>
#include <string>
#include <isstream>
using namespace std;

void printBoard(string board[]) {

}

void placeship(){

}

void play() {

}

void end() {

}

void num_moves(){

}

int main() {
    //choose game mode
    int mapx = 10; // map width
    int mapy = 10; // map length
    string **map = new string*[mapx]; // create a 2d dynamic array
    for(int i = 0; i < mapx; ++i) {
    map[i] = new string[mapy];
    }
    cout << "Welcome to Battleship!" << endl;
    cout << "Please choose a game mode: " << endl;

    for(int i = 0; i < mapx; ++i) { // delete the 2d dynamic array
    delete [] map[i];
    }
    delete [] map;
    return 0;
}
