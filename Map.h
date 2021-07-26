//
// Created by paul on 26/07/2021.
//

#ifndef CONWAYS_GOL_MAP_H
#define CONWAYS_GOL_MAP_H

const int MAP_HEIGHT = 10;
const int MAP_WIDTH = 40;

void printMap(bool map[MAP_WIDTH][MAP_HEIGHT]);
int countNeighboursAlive(bool map[MAP_WIDTH][MAP_HEIGHT], int x, int y);
void countNeighboursAlive(bool map[MAP_WIDTH][MAP_HEIGHT], int nMap[MAP_WIDTH][MAP_HEIGHT]);
void printCountNeighboursAlive(bool map[MAP_WIDTH][MAP_HEIGHT]);
void renderMap(bool map[MAP_WIDTH][MAP_HEIGHT]);

#endif //CONWAYS_GOL_MAP_H
