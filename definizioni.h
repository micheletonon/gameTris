#ifndef DEFINIZIONI_H
#define DEFINIZIONI_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

// Costanti del programma
#define FPS 30
#define BASE_WIDTH 1280.0f  // Risoluzione di riferimento
#define BASE_HEIGHT 720.0f
#define MARGINE 100.0f

// Dichiarazioni variabili globali Allegro (definite in tris.c)
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_FONT *font;
extern ALLEGRO_FONT *font_large;


// Dichiarazioni variabili configurazione schermo (definite in tris.c)
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern float SCALE_FACTOR;

#endif
