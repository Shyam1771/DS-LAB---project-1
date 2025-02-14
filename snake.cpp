#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <unistd.h>

using namespace std;

class SnakeGame {
private:
    bool gameOver;
    const int width = 20;
    const int height = 20;
    int x, y, fruitX, fruitY, score, highScore;
    int tailX[100], tailY[100], nTail;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

public:
    SnakeGame() {
        srand(time(0));
        Setup();
    }

    void Setup() {
        gameOver = false;
        dir = STOP; 
        x = width / 2;
        y = height / 2;
        score = 0;
        nTail = 2;
        tailX[0] = x; tailY[0] = y + 1;
        tailX[1] = x; tailY[1] = y + 2;
        
        highScore = 0;
        GenerateFruit();
    }

    void GenerateFruit() {
        do {
            fruitX = rand() % width;
            fruitY = rand() % height;
        } while (IsFruitOnSnake());
    }

    bool IsFruitOnSnake() {
        for (int i = 0; i < nTail; i++) {
            if (tailX[i] == fruitX && tailY[i] == fruitY)
                return true;
        }
        return false;
    }

    void Draw() {
        cout << "\033[H\033[J";
        for (int i = 0; i < width + 2; i++) cout << "#";
        cout << endl;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) cout << "#";
                
                if (i == y && j == x) cout << "O";  
                else if (i == fruitY && j == fruitX) cout << "F";  
                else {
                    bool print = false;
                    for (int k = 0; k < nTail; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            cout << "o";  
                            print = true;
                        }
                    }
                    if (!print) cout << " ";
                }
                
                if (j == width - 1) cout << "#";
            }
            cout << endl;
        }
        
        for (int i = 0; i < width + 2; i++) cout << "#";
        cout << "\nScore: " << score << "  High Score: " << highScore << endl;
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a': dir = LEFT; break;
                case 'd': dir = RIGHT; break;
                case 'w': dir = UP; break;
                case 's': dir = DOWN; break;
                case 'x': gameOver = true; break;
            }
        }
    }

    void MoveSnake() {
        int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < nTail; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
    }

    void CheckCollision() {
        if (x < 0 || x >= width || y < 0 || y >= height)
            gameOver = true;
        for (int i = 0; i < nTail; i++) {
            if (tailX[i] == x && tailY[i] == y) {
                gameOver = true;
            }
        }
    }

    void EatFood() {
        if (x == fruitX && y == fruitY) {
            score += 10;
            if (score > highScore) highScore = score;
            nTail++;
            GenerateFruit();
        }
    }

    void Logic() {
        MoveSnake();
        switch (dir) {
            case LEFT: x--; break;
            case RIGHT: x++; break;
            case UP: y--; break;
            case DOWN: y++; break;
            default: break;
        }
        CheckCollision();
        EatFood();
    }

    void GameOverScreen() {
        cout << "\nGame Over! Final Score: " << score << "\n";
        cout << "Highest Score: " << highScore << "\n";
        cout << "Press 'r' to Restart or 'q' to Quit: ";
        char choice;
        cin >> choice;
        if (choice == 'r') {
            Setup();
            Run();
        }
    }

    void Run() {
        while (!gameOver) {
            Draw();
            Input();
            if (dir != STOP) Logic(); 
            usleep(100000);  
        }
        GameOverScreen();
    }
};

int main() {
    SnakeGame game;
    game.Run();
    return 0;
}
