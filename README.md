# Tic-Tac-Toe Game in C with Allegro

A simple Tic-Tac-Toe (Tris) game implementation in C using the Allegro 5 library. This project was created to explore and demonstrate video game development in C.

## About

This is a basic implementation of the classic Tic-Tac-Toe game, built entirely in C. The project uses the Allegro 5 multimedia library for graphics, user input, and event handling. It serves as an educational example of how to develop a simple video game in C, covering fundamental concepts such as:

- Graphics rendering and display management
- Event-driven programming
- Game state management
- User input handling
- Basic game logic implementation

## Requirements

- C compiler (GCC, Clang, or similar)
- Allegro 5 library and its dependencies:
  - allegro5
  - allegro_font
  - allegro_ttf
  - allegro_primitives
  - allegro_image

## Building

To compile the project, use a C compiler with Allegro 5 linked:

```bash
gcc tris.c game.c sfondo.c -o tris -lallegro -lallegro_font -lallegro_ttf -lallegro_primitives -lallegro_image
```

Or use your preferred build system.

## Running

After building, simply run the executable:

```bash
./tris
```

## Project Structure

- `tris.c` - Main program entry point and initialization
- `game.c` - Core game logic and gameplay implementation
- `sfondo.c` - Background rendering functionality
- `*.h` - Header files with function declarations and definitions

## License

This project is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.

## Contributing

Feel free to fork this project and experiment with it. Contributions, suggestions, and improvements are welcome!
