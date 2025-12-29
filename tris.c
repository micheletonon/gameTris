
#include "tris.h"


int main(int argc, char *argv[])
{
    definisce_screen();
    if(inizializza_allegro() != 0)
    {
        return -1;
    }



    // disegna lo sfondo iniziale
    sfondo();
    al_flip_display();  // Mostra lo sfondo iniziale


    // avvia il gioco
    game();


    distrugge();
    return 0;
}


void definisce_screen()
{
    printf("DIMENSIONI SCHERMO (Invio per usare i default %dx%d):\n", SCREEN_WIDTH, SCREEN_HEIGHT);

    char input[100];
    int temp_width, temp_height;

    printf("Larghezza [%d]: ", SCREEN_WIDTH);
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &temp_width) == 1) {
        SCREEN_WIDTH = temp_width;
    }

    printf("Altezza [%d]: ", SCREEN_HEIGHT);
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &temp_height) == 1) {
        SCREEN_HEIGHT = temp_height;
    }

}

int inizializza_allegro()
{

    // Inizializza Allegro
    if (!al_init()) {
        fprintf(stderr, "Errore: impossibile inizializzare Allegro!\n");
        return -1;
    }

    // Inizializza addon
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();


    // Calcola fattore di scala (usa l'altezza come riferimento)
    SCALE_FACTOR = (float)SCREEN_HEIGHT / BASE_HEIGHT;

    printf("Risoluzione: %dx%d (scala: %.2f)\n", SCREEN_WIDTH, SCREEN_HEIGHT, SCALE_FACTOR);




    // Crea display in modalità finestra
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!display) {
        fprintf(stderr, "Errore: impossibile creare display!\n");
        return -1;
    }
    al_set_window_title(display, "Tris Game");

    // Carica font TrueType con dimensioni leggibili
    // Scala dimensioni font in base alla risoluzione
    int font_size = SCREEN_HEIGHT / 36;  // ~30px per 1080p
    int font_large_size = SCREEN_HEIGHT / 22;  // ~48px per 1080p

    printf("Dimensioni font: normale=%d, grande=%d\n", font_size, font_large_size);

    // Prova vari font di sistema comuni su macOS
    const char* font_paths[] = {
        "/System/Library/Fonts/Helvetica.ttc",
        "/System/Library/Fonts/SFNSText.ttf",
        "/Library/Fonts/Arial.ttf",
        "/System/Library/Fonts/Supplemental/Arial.ttf",
        NULL
    };

    font = NULL;
    for (int i = 0; font_paths[i] != NULL; i++) {
        font = al_load_ttf_font(font_paths[i], font_size, 0);
        if (font) break;
    }
    if (!font) {
        fprintf(stderr, "Avviso: impossibile caricare font TTF, uso builtin\n");
        font = al_create_builtin_font();
    }

    font_large = NULL;
    for (int i = 0; font_paths[i] != NULL; i++) {
        font_large = al_load_ttf_font(font_paths[i], font_large_size, 0);
        if (font_large) break;
    }
    if (!font_large) {
        fprintf(stderr, "Avviso: impossibile caricare font large TTF, uso builtin\n");
        font_large = al_create_builtin_font();
    }
    
    // Timer e coda eventi
    timer = al_create_timer(1.0 / FPS);
    event_queue = al_create_event_queue();
    
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    

    
    // Avvia timer
    al_start_timer(timer);

    return 0;
}

/*************************************************************
 * distrugge e libera la memoria
 **************************************************************/
void distrugge(){
    al_destroy_font(font);
    al_destroy_font(font_large);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
}