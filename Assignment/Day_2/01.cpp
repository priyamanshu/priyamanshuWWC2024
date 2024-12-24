#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int GRID_SIZE = 5; // Size of the grid
const char EMPTY = '.';   // Empty cell
const char FRUIT = 'F';   // Fruit cell
const char PLAYER = 'P';   // Player symbol

class FruitJunction {
private:
    vector<vector<char>> grid;
    int playerX, playerY;
    int score;

public:
    FruitJunction() : score(0) {
        grid.resize(GRID_SIZE, vector<char>(GRID_SIZE, EMPTY));
        playerX = GRID_SIZE / 2; // Start in the middle of the grid
        playerY = GRID_SIZE / 2;
        placeFruit();
    }

    void placeFruit() {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y] != EMPTY); // Ensure the fruit is placed in an empty cell
        grid[x][y] = FRUIT;
    }

    void displayGrid() {
        system("clear"); // Use "cls" on Windows
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (i == playerX && j == playerY) {
                    cout << PLAYER << " "; // Display player
                } else {
                    cout << grid[i][j] << " "; // Display grid content
                }
            }
            cout << endl;
        }
        cout << "Score: " << score << endl;
    }

    void movePlayer(char direction) {
        int newX = playerX;
        int newY = playerY;

        switch (direction) {
            case 'w': newX--; break; // Move up
            case 's': newX++; break; // Move down
            case 'a': newY--; break; // Move left
            case 'd': newY++; break; // Move right
            default: cout << "Invalid move!" << endl; return;
        }

        // Check boundaries
        if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE) {
            playerX = newX;
            playerY = newY;

            // Check for fruit collection
            if (grid[playerX][playerY] == FRUIT) {
                score++;
                grid[playerX][playerY] = EMPTY; // Remove the fruit
                placeFruit(); // Place a new fruit
            }
        } else {
            cout << "Move out of bounds!" << endl;
        }
    }

    void play() {
        char move;
        while (true) {
            displayGrid();
            cout << "Enter your move (w/a/s/d) or 'q' to quit: ";
            cin >> move;

            if (move == 'q') {
                cout << "Thanks for playing! Your final score is: " << score << endl;
                break;
            }

            movePlayer(move);
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    FruitJunction game;
    game.play();
    return 0;
}