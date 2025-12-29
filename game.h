#ifndef GAME_H
#define GAME_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>



void game();
bool writeX_O(int position);
void redraw_all();
void draw_move(int position, bool is_X);
int getVittoria();

#endif