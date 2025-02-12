# DS-LAB---project-1
# Snake Game

## Overview
This is a simple terminal-based Snake Game implemented in C++. The game runs in a loop where the player controls the snake to collect food while avoiding collisions. The score increases as the snake eats food, and the game ends if the snake collides with itself.

## Features
- Classic Snake Gameplay: Move the snake using 'w', 'a', 's', 'd' keys.
- Food Collection: The snake grows upon eating food, and the score increases.
- Boundary Wrapping: The snake reappears on the opposite side if it crosses the screen edges.
- Game Over Conditions: Collision with the snake's own body ends the game. OR hitting the wall
- Simple Console Interface: Uses ASCII characters to represent the game elements.

## How It Works
1. Setup Phase: Initializes game variables, places the snake at the center, and randomly positions the food.
2. Drawing the Game: The board is displayed using ASCII characters:
   - # represents the walls.
   - O represents the snake's head.
   - o represents the snake's tail.
   - F represents the food.
3. User Input Handling: The player uses:
   - 'w' to move up
   - 'a' to move left
   - 's' to move down
   - 'd' to move right
   - 'x' to exit the game
4. Game Logic:
   - The snake moves in the specified direction.
   - If the snake eats food, it grows and the score increases.1 fruit = 10 points
   - If the snake collides with itself OR hit the wall the game ends.
5. Game over:
   - if game is over click 'r' to restart or click 'q' to quit

## Special Mentions
- Smooth Movement: The game uses usleep(100000); to control the speed of the snake.
- Efficient Tail Handling: The tail follows the head dynamically.
- shows the highscore.
- to stop flickering we are using - cout << "\033[H\033[J"; (\033 - esc, [H - cursor goes to row1 col1, [J - clears the screen)

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
