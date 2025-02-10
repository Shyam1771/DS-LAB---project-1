# DS-LAB---project-1
# Snake Game

## Overview
This is a simple terminal-based Snake Game implemented in C++. The game runs in a loop where the player controls the snake to collect food while avoiding collisions. The score increases as the snake eats food, and the game ends if the snake collides with itself.

## Features
- Classic Snake Gameplay: Move the snake using 'W', 'A', 'S', 'D' keys.
- Food Collection: The snake grows upon eating food, and the score increases.
- Boundary Wrapping: The snake reappears on the opposite side if it crosses the screen edges.
- Game Over Conditions: Collision with the snake's own body ends the game.
- Simple Console Interface: Uses ASCII characters to represent the game elements.

## How It Works
1. Setup Phase: Initializes game variables, places the snake at the center, and randomly positions the food.
2. Drawing the Game: The board is displayed using ASCII characters:
   - # represents the walls.
   - O represents the snake's head.
   - o represents the snake's tail.
   - F represents the food.
3. User Input Handling: The player uses:
   - 'W' to move up
   - 'A' to move left
   - 'S' to move down
   - 'D' to move right
   - 'X' to exit the game
4. Game Logic:
   - The snake moves in the specified direction.
   - If the snake eats food, it grows and the score increases.
   - If the snake collides with itself, the game ends.

## Special Mentions
- Smooth Movement: The game uses usleep(100000); to control the speed of the snake.
- Boundary Handling: The snake wraps around the edges instead of stopping.
- Efficient Tail Handling: The tail follows the head dynamically.

## How to Run
1. Compile the program using a C++ compiler:
   sh
   g++ snake_game.cpp -o snake_game
   
2. Run the executable:
   sh
   ./snake_game
   
3. Control the snake using the specified keys.

## Notes
- The game runs in a terminal/command prompt.
- Works best on Unix-based systems due to the system("clear") command.
- The input method may need modifications for real-time key capture on Windows.

Enjoy the game!
