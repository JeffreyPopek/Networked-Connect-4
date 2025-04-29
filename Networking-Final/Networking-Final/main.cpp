#include "raylib.h"
#include <array>
#include <iostream>

const int ROWS = 6;
const int COLUMNS = 7;
const int CELL_SIZE = 100;

enum Player { NONE = 0, PLAYER1, PLAYER2 };

// 2d array board
std::array<std::array<Player, COLUMNS>, ROWS> board = {};

// Game state vars
Player currentPlayer = PLAYER1;
int selectedColumn = 0;
bool gameOver = false;
Player winner = NONE;
Color pieceColor;

bool DropPiece(int col, Player player)
{
    for (int row = ROWS - 1; row >= 0; --row)
    {
        if (board[row][col] == NONE)
        {
			// set board position to player
            board[row][col] = player;
            return true;
        }
    }
    return false; 

}

bool CheckWin(Player player)
{
    // implement
    switch (player)
    {
    case NONE:
        break;
    case PLAYER1:
        currentPlayer = PLAYER2;
        pieceColor = YELLOW;
        break;
    case PLAYER2:
        currentPlayer = PLAYER1;
        pieceColor = RED;
        break;
    default:
        break;
    }
    return false;

    return false;
}

bool IsBoardFull()
{
    for (int row = 0; row < ROWS; ++row)
    {
        for (int col = 0; col < COLUMNS; ++col)
        {
            if (board[row][col] == NONE)
                return false;
        }
    }
    return true; 
}


int main()
{
    int screenWidth = COLUMNS * CELL_SIZE;
    int screenHeight = (ROWS + 1) * CELL_SIZE;

    InitWindow(screenWidth, screenHeight, "connect 4 tuah!");

    SetTargetFPS(60);

    pieceColor = RED;

    while (!WindowShouldClose())
    {
        if (!gameOver)
        {
            // move on top
            if (IsKeyPressed(KEY_LEFT))  
                selectedColumn = (selectedColumn - 1 + COLUMNS) % COLUMNS;

            else if (IsKeyPressed(KEY_RIGHT)) 
                selectedColumn = (selectedColumn + 1) % COLUMNS;

            // place piece
            else if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
            {
                // drop piece in column
                if (DropPiece(selectedColumn, currentPlayer))
                {
                    // check for player win based on player and switch player
                    if (CheckWin(currentPlayer))
                    {
                        gameOver = true;
                        winner = currentPlayer;
                    }
                    else if (IsBoardFull())
                    {
                        std::cout << "GAME TIED" << std::endl;
                        gameOver = true;
                        winner = NONE;
                    }
                }
            }
        }
        else
        {
            if (IsKeyPressed(KEY_R))
            {
                // reset game and values
                board = {};
                gameOver = false;
                winner = NONE;
                currentPlayer = PLAYER1;
                selectedColumn = 0;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // selection
        for (int col = 0; col < COLUMNS; col++)
        {
			if (col == selectedColumn)
				DrawRectangle(col * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE, pieceColor);
			else
				DrawRectangle(col * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE, LIGHTGRAY);
        }

        // Draw board
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLUMNS; col++)
            {
                int x = col * CELL_SIZE + CELL_SIZE / 2;
                int y = (row + 1) * CELL_SIZE + CELL_SIZE / 2;

                Color color = LIGHTGRAY;

                if (board[row][col] == PLAYER1) 
                    color = RED;
                else if (board[row][col] == PLAYER2) 
                    color = YELLOW;

                DrawCircle(x, y, CELL_SIZE / 2 - 10, color);
            }
        }

        // draw game state messages
        if (gameOver)
        {
            switch (winner)
            {
                case NONE:
                    DrawText("Draw?! Press R to restart", 50, 10, 20, BLACK);
                    break;
                case PLAYER1:
                    DrawText("Player 1 Wins! Press R to restart", 50, 10, 20, RED);
                    break;
                case PLAYER2:
                    DrawText("Player 2 Wins! Press R to restart", 50, 10, 20, YELLOW);
                    break;
                default:
                    break;
            }
        }
        else
        {
            switch (currentPlayer)
            {
                case NONE:
                    // fortnite battle pass 19 dolalrs
                    break;
                case PLAYER1:
                    DrawText("Player 1's Turn (Red)", 50, 10, 20, BLACK);
                    break;
                case PLAYER2:
                    DrawText("Player 2's Turn (Yellow)", 50, 10, 20, BLACK);
                    break;
                default:
                    break;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
