

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>



#include "definizioni.h"
#include "sfondo.h"
#include "game.h"


// Definizioni delle variabili globali (dichiarate in definizioni.h)
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_FONT *font = NULL;
ALLEGRO_FONT *font_large = NULL;

int SCREEN_WIDTH = 1920;
int SCREEN_HEIGHT = 1080;
float SCALE_FACTOR = 1.0f;



int inizializza_allegro();
void definisce_screen();

int main(int argc, char *argv[]);
void distrugge();