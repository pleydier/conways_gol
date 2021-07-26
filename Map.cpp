//
// Created by paul on 26/07/2021.
//

#include <iostream>
#include "Map.h"


void printMap(bool map[MAP_WIDTH][MAP_HEIGHT]) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (map[x][y]) {
                std::cout << "\u25A0" << " ";
            } else {
                std::cout << "\u25A1" << " ";
            }
        }
        std::cout << std::endl;
    }
}

int countNeighboursAlive(bool map[MAP_WIDTH][MAP_HEIGHT], int x, int y) {
    int count{0};
    // count on the previous column
    if (x - 1 >= 0) {
        if (y - 1 >= 0) {
            if (map[x - 1][y - 1]) {
                count++;
            }
        }
        if (map[x - 1][y]) {
            count++;
        }
        if (y + 1 < MAP_HEIGHT) {
            if (map[x - 1][y + 1]) {
                count++;
            }
        }
    }
    // count on the same column
    if (y - 1 >= 0) {
        if (map[x][y - 1]) {
            count++;
        }
    }
    if (y + 1 < MAP_HEIGHT) {
        if (map[x][y + 1]) {
            count++;
        }
    }
    // count on the next column
    if (x + 1 < MAP_WIDTH) {
        if (y - 1 >= 0) {
            if (map[x + 1][y - 1]) {
                count++;
            }
        }
        if (map[x + 1][y]) {
            count++;
        }
        if (y + 1 < MAP_HEIGHT) {
            if (map[x + 1][y + 1]) {
                count++;
            }
        }
    }
    return count;
}

void countNeighboursAlive(bool map[MAP_WIDTH][MAP_HEIGHT], int nMap[MAP_WIDTH][MAP_HEIGHT]) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            nMap[x][y] = countNeighboursAlive(map, x, y);
        }
    }
}

void printCountNeighboursAlive(bool map[MAP_WIDTH][MAP_HEIGHT]) {
    int nMap[MAP_WIDTH][MAP_HEIGHT]{};
    countNeighboursAlive(map, nMap);
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            std::cout << nMap[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

void renderMap(bool map[MAP_WIDTH][MAP_HEIGHT]) {
    int neighboursMap[MAP_WIDTH][MAP_HEIGHT]{};
    countNeighboursAlive(map, neighboursMap);
    for (int y = 0; y < MAP_WIDTH; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (map[x][y] && (neighboursMap[x][y] < 2 || neighboursMap[x][y] > 3)) { // alive cell dies
                map[x][y] = false;
            } else if (!map[x][y] && neighboursMap[x][y] == 3) { // dead cell comes to life
                map[x][y] = true;
            }
        }
    }
}
