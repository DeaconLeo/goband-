#ifndef DRAW_H
#define DRAW_H
#include <graphics.h>
#include <string.h>


//draw pieces into the chessgrid
void draw_chessPiece(int r,int c,int color);
//show mouse position
void showMousePosition(int x, int y);
//draw the background and the line of chessgrid
ege::PIMAGE imgbuf();
#endif // DRAW_H
