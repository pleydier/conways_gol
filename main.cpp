#include <iostream>
#include "Map.h"
using namespace std;


int main() {
    bool map[MAP_WIDTH][MAP_HEIGHT]{};
    cout << "Initialization:" << endl;

    //lwss
    map[0][0] = true;
    map[1][1] = true;
    map[2][1] = true;
    map[0][2] = true;
    map[1][2] = true;

    printMap(map);
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << "Round " << i << endl;
        renderMap(map);
        printMap(map);
        cout << endl;
    }
}
