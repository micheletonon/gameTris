#include "sfondo.h"
#include "definizioni.h"

/**************************************************************
 * genera lo sfondo
 *************************************************************/

void sfondo()
{
    // scrive il titolo
    al_draw_text(font_large, al_map_rgb(255, 200, 50), SCREEN_WIDTH / 2, 10 * SCALE_FACTOR, ALLEGRO_ALIGN_CENTER, "TRIS GAME");

    // disegna il tris: divide lo schermo in 3 parti per avere 2 linee equidistanti  1 | 2 | 3 
    int n = 3;
    for(int i = 1; i<n; i++)
    {
        al_draw_line(SCREEN_WIDTH/n*i, MARGINE, SCREEN_WIDTH/n*i, SCREEN_HEIGHT - MARGINE, al_map_rgb(255, 200, 50), 1);
    }
    for(int i = 1; i<n; i++)
    {
        al_draw_line(MARGINE, SCREEN_HEIGHT/n*i, SCREEN_WIDTH - MARGINE, SCREEN_HEIGHT/n*i, al_map_rgb(255, 200, 50), 1);
    }
    // disegna un numero su ogni cella
    int t = 1;
    for(int y=0;y<n;y++)
        for(int x=0;x<n;x++)
        {
            char testo[2];
            sprintf(testo, "%d", t);
            al_draw_text(font, al_map_rgb(255, 200, 50), SCREEN_WIDTH/n*x+MARGINE/2, SCREEN_HEIGHT/n*y+MARGINE/2, ALLEGRO_ALIGN_CENTER, testo);
            t++;
        }
    // Rimosso al_flip_display() - ora viene fatto dal chiamante
}
