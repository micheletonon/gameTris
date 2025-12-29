# Makefile per Cannon Game
# Allegro 5 Artillery Battle

CC = gcc
CFLAGS = -Wall -O2
LIBS = -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lm

# Alternativa con pkg-config (più portabile) - CONSIGLIATO per macOS
CFLAGS += $(shell pkg-config --cflags allegro_main-5 allegro-5 allegro_primitives-5 allegro_font-5 allegro_ttf-5)
LIBS = $(shell pkg-config --libs allegro_main-5 allegro-5 allegro_primitives-5 allegro_font-5 allegro_ttf-5) -lm

TARGET = tris
SRC = tris.c sfondo.c game.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

clean:
	rm -f $(TARGET)

# Per sistemi che usano pkg-config
pkg-config:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $$(pkg-config --cflags --libs allegro_main-5 allegro-5 allegro_primitives-5 allegro_font-5 allegro_ttf-5) -lm

.PHONY: all clean pkg-config