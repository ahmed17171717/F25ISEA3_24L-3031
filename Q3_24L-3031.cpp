#include <iostream>
using namespace std;

//======================== FUNCTION DECLARATIONS ========================
void displayBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool isBoardFull(char board[3][3]);
void playGame();
bool getValidInput(int& row, int& col);

//============================ MAIN FUNCTION ============================
int main()
{
    cout << "========================================" << endl;
    cout << "           TIC-TAC-TOE GAME             " << endl;
    cout << "========================================" << endl;
    cout << "Player 1: X  |  Player 2: O" << endl;
    cout << "Enter Position (row , col): 0-2 for each" << endl;
    cout << "========================================" << endl;

    playGame();
    return 0;
}

//======================== FUNCTION DEFINITIONS ========================

///<summary>
///Displays the Tic-Tac-Toe board.
///</summary>
void displayBoard(char board[3][3])
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << " ";
            if (j < 2)
                cout << "|";
        }
        cout << "\n";
        if (i < 2)
            cout << "---|---|---\n";
    }
    cout << "\n";
}

///<summary>
/// Checks if a player has won.
///</summary>
bool checkWin(char board[3][3], char player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

///<summary>
/// Checks if the board is full.
///</summary>
bool isBoardFull(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

/// <summary>
/// Gets valid numeric input for row and column.
/// Ensures user input is numeric and between 0–2.
/// </summary>
bool getValidInput(int& row, int& col)
{
    cout << "Enter row (0-2): ";
    cin >> row;

    if (cin.fail())  // If the user enter something other than a number cin.fail() is called
    {
        cin.clear();  // This function resets the error state of cin after a failure.
        cin.ignore(1000, '\n'); // Skip invalid inputs
        cout << "Invalid input! Please enter a number between 0 and 2.\n" << endl;
        return false;
    }

    cout << "Enter column (0-2): ";
    cin >> col;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Please enter a number between 0 and 2.\n" << endl;
        return false;
    }

    // Check range
    if (row < 0 || row > 2 || col < 0 || col > 2)
    {
        cout << "Invalid position! Row and column must be between 0 and 2.\n" << endl;
        return false;
    }

    return true;
}

/// <summary>
/// Main game loop for playing Tic-Tac-Toe.
/// </summary>
void playGame()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char currentPlayer = 'X';
    int row, col;

    displayBoard(board);

    while (true)
    {
        cout << "Player " << currentPlayer << "'s turn" << endl;

        // Keep asking until valid input
        if (!getValidInput(row, col))
            continue;

        // Check if position already filled
        if (board[row][col] != ' ')
        {
            cout << "Position already taken! Try again.\n" << endl;
            continue;
        }

        // Place the player's mark
        board[row][col] = currentPlayer;

        displayBoard(board);

        // Check win condition
        if (checkWin(board, currentPlayer))
        {
            cout << "========================================" << endl;
            cout << "Player " << currentPlayer << " wins!" << endl;
            cout << "========================================" << endl;
            break;
        }

        // Check draw condition
        if (isBoardFull(board))
        {
            cout << "========================================" << endl;
            cout << "Game Drawn!" << endl;
            cout << "========================================" << endl;
            break;
        }

        // Switch player
        if (currentPlayer == 'X')
        {
            currentPlayer = 'O';
        }
        else
        {
            currentPlayer = 'X';
        }
    }
}


        
    
