#include "game.h"
#include "definizioni.h"
#include "sfondo.h"

// se player è false è giocatore 1 (X) altrimenti è giovatore 2 (O)
bool player = true;

// Array per tenere traccia dello stato del gioco
// 0 = vuoto, 1 = X, 2 = O
int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int drawVittoria=0;


void game()
{
    // Avvia timer
    al_start_timer(timer);
    
    bool running = true;
    bool redraw = true;
    
    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }
        else if (event.type == ALLEGRO_EVENT_TIMER) {
            // Update
            // Non serve redraw continuo per un gioco a turni
        }
        else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(event.keyboard.keycode)
            {
                case ALLEGRO_KEY_ESCAPE:
                    // chiusura gioco
                    running = false;
                break;

                case ALLEGRO_KEY_1:
                    redraw = writeX_O(1);
                break;
                case ALLEGRO_KEY_2:
                    redraw = writeX_O(2);
                break;
                case ALLEGRO_KEY_3:
                    redraw = writeX_O(3);
                break;
                case ALLEGRO_KEY_4:
                    redraw = writeX_O(4);
                break;
                case ALLEGRO_KEY_5:
                    redraw = writeX_O(5);
                break;
                case ALLEGRO_KEY_6:
                    redraw = writeX_O(6);
                break;
                case ALLEGRO_KEY_7:
                    redraw = writeX_O(7);
                break;
                case ALLEGRO_KEY_8:
                    redraw = writeX_O(8);
                break;
                case ALLEGRO_KEY_9:
                    redraw = writeX_O(9);
                break;
            }
                    
        }

        // rileva la vittoria
        int v = getVittoria();

        // Rendering
        if (redraw) {
            redraw = false;
            redraw_all();  // Ridisegna tutto (sfondo + mosse)
            al_flip_display();
        }

        // se uno vince esce dal gioco dopo 10 secondi
        if(v != 0)
        {
            sleep(10);
            running = false;
        }
    }

}

bool writeX_O(int position)
{
    // Controlla se la posizione è valida (1-9)
    if(position < 1 || position > 9)
        return false;

    // Controlla se la cella è già occupata
    if(board[position - 1] != 0)
        return false;  // Cella già occupata, non fare nulla

    // Salva la mossa nell'array
    if(player)
    {
        board[position - 1] = 1;  // X
    }
    else
    {
        board[position - 1] = 2;  // O
    }

    // Cambia giocatore
    player = !player;

    // Ritorna true per far ridisegnare lo schermo
    return true;
}

// funzione che rileva la vittoria
int getVittoria()
{
    // controlla le righe
    if(board[0] != 0 && board[0] == board[1] && board[1] == board[2])
    {
        // prima linea
        drawVittoria=1;
        // ritorna chi ha vinto
        return board[0];
    }
    if(board[3] != 0 && board[3] == board[4] && board[4] == board[5])
    {
        // seconda riga
        drawVittoria=2;
        // ritorna chi ha vinto
        return board[2];
    }
    if(board[6] != 0 && board[6] == board[7] && board[7] == board[8])
    {
        // terza riga
        drawVittoria=3;
        // ritorna chi ha vinto
        return board[6];
    }
    // controlla le diagonali
    if(board[0] != 0 && board[0] == board[4] && board[4] == board[8])
    {
        // prima diagonale
        drawVittoria=4;
        // ritorna chi ha vinto
        return board[0];
    }
    if(board[2] != 0 && board[2] == board[4] && board[4] == board[6])
    {
        // prima diagonale
        drawVittoria=5;
        // ritorna chi ha vinto
        return board[2];
    }
    // controlla le verticali
    if(board[0] != 0 && board[0] == board[3] && board[3] == board[6])
    {
        // prima linea
        drawVittoria=6;
        // ritorna chi ha vinto
        return board[0];
    }
    if(board[1] != 0 && board[1] == board[4] && board[4] == board[7])
    {
        // seconda riga
        drawVittoria=7;
        // ritorna chi ha vinto
        return board[1];
    }
    if(board[2] != 0 && board[2] == board[5] && board[5] == board[8])
    {
        // terza riga
        drawVittoria=8;
        // ritorna chi ha vinto
        return board[2];
    }
    // nessuno vince
    return 0;
}

// Funzione per disegnare X o O in una posizione specifica
void draw_move(int position, bool is_X)
{
    float x1, y1, x2, y2, cx, cy, r;
    int pX, pY;

    // Converti position (1-9) in coordinate griglia (0-2, 0-2)
    pX = (position - 1) % 3;
    pY = (position - 1) / 3;

    x1 = SCREEN_WIDTH/3*pX+MARGINE;
    y1 = SCREEN_HEIGHT/3*pY+MARGINE;
    x2 = SCREEN_WIDTH/3*(1+pX)-MARGINE;
    y2 = SCREEN_HEIGHT/3*(1+pY)-MARGINE;
    cx = SCREEN_WIDTH/3*pX+SCREEN_WIDTH/3/2;
    cy = SCREEN_HEIGHT/3*pY+SCREEN_HEIGHT/3/2;
    r  = (SCREEN_HEIGHT/3)/2 - MARGINE;

    if(is_X)
    {
        // scrive X in verde
        al_draw_line(x1, y1, x2, y2, al_map_rgb(0, 255, 0), 1);
        al_draw_line(x2, y1, x1, y2, al_map_rgb(0, 255, 0), 1);
    }
    else
    {
        // scrive O in rosso
        al_draw_circle(cx, cy, r, al_map_rgb(255, 0, 0), 1);
    }
}

// Ridisegna l'intero schermo (sfondo + tutte le mosse)
void redraw_all()
{
    sfondo();

    // Ridisegna tutte le mosse fatte
    for(int i = 0; i < 9; i++)
    {
        if(board[i] == 1)
        {
            draw_move(i + 1, true);  // X
        }
        else if(board[i] == 2)
        {
            draw_move(i + 1, false); // O
        }
    }

    // disegna le vittorie con linea gialla grossa
    switch(drawVittoria)
    {
        // prima riga
        case 1:
            al_draw_line(MARGINE, SCREEN_HEIGHT/3/2, SCREEN_WIDTH-MARGINE, SCREEN_HEIGHT/3/2, al_map_rgb(255, 255, 0), 5);
            break;
        // seconda riga
        case 2:
            al_draw_line(MARGINE, SCREEN_HEIGHT/3+SCREEN_HEIGHT/3/2, SCREEN_WIDTH-MARGINE, SCREEN_HEIGHT/3+SCREEN_HEIGHT/3/2, al_map_rgb(255, 255, 0), 5);
            break;
        // terza riga
        case 3:
            al_draw_line(MARGINE, SCREEN_HEIGHT/3*2+SCREEN_HEIGHT/3/2, SCREEN_WIDTH-MARGINE, SCREEN_HEIGHT/3*2+SCREEN_HEIGHT/3/2, al_map_rgb(255, 255, 0), 5);
            break;
        // prima diagonale (da alto-sinistra a basso-destra)
        case 4:
            al_draw_line(MARGINE, MARGINE, SCREEN_WIDTH-MARGINE, SCREEN_HEIGHT-MARGINE, al_map_rgb(255, 255, 0), 5);
            break;
        // seconda diagonale (da alto-destra a basso-sinistra)
        case 5:
            al_draw_line(SCREEN_WIDTH-MARGINE, MARGINE, MARGINE, SCREEN_HEIGHT-MARGINE, al_map_rgb(255, 255, 0), 5);
            break;
        // prima colonna
        case 6:
            al_draw_line(SCREEN_WIDTH/3/2, MARGINE, SCREEN_WIDTH/3/2, SCREEN_HEIGHT-MARGINE, al_map_rgb(255, 255, 0), 5);
            break;
        // seconda colonna
        case 7:
            al_draw_line(SCREEN_WIDTH/3+SCREEN_WIDTH/3/2, MARGINE, SCREEN_WIDTH/3+SCREEN_WIDTH/3/2, SCREEN_HEIGHT-MARGINE, al_map_rgb(255, 255, 0), 5);
            break;
        // terza colonna
        case 8:
            al_draw_line(SCREEN_WIDTH/3*2+SCREEN_WIDTH/3/2, MARGINE, SCREEN_WIDTH/3*2+SCREEN_WIDTH/3/2, SCREEN_HEIGHT-MARGINE, al_map_rgb(255, 255, 0), 5);
            break;
    }
}

