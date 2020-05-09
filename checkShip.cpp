#include <iostream>
#include "checkShip.h"

using namespace std;

void checkShip(char ** ptr, string * pos, int & overall, int & size_of_array) {

  int size_check = 0;

  for (int i = 0; i < size_of_array ; ++i){ // transverse the position of ship
    if (pos[i][0] == 'V'){ // check for ship's orientation
      for (int j = (pos[i][2]-'0'); j > ((pos[i][2]-'0')-(pos[i][1]-'0')) ; --j){
        if (ptr[j][pos[i][3]-'0'] == 'O') // check if user hit all position of ship
          size_check += 1;
      }
    }
    else {
      for (int j = (pos[i][3]-'0'); j > ((pos[i][3]-'0')-(pos[i][1]-'0')) ; --j){
        if (ptr[pos[i][2]-'0'][j] == 'O')
          size_check += 1;
      }
    }

    if (size_check == pos[i][1] -'0') {
      cout << "Congrats, soldier!" << endl;
      if (pos[i][4] == '0')
        cout << "You have sunk enemy's Carrier!" << endl;
      else if (pos[i][4] == '1')
        cout << "You have sunk enemy's Battleship!" << endl;
      else if (pos[i][4] == '2')
        cout << "You have sunk enemy's Crusier!" << endl;
      else if (pos[i][4] == '3')
        cout << "You have sunk enemy's Submarine!" << endl;
      else if (pos[i][4] == '4')
        cout << "You have sunk enemy's Destroyer!" << endl;
      overall += 1;
      for (int k = 0; k < size_of_array-1; ++k){
        if (k >= i){
          pos[k] = pos[k+1];
        }
      }
      size_of_array--;
    }
    size_check = 0;
  }
}
