#include <bits/stdc++.h>
using namespace std;

string toUpperCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

void printBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << " -----------------" << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << " | " << board[i][j] << " ";
        }
        cout << " |" << endl;
    }
    cout << " -----------------" << endl;
}

bool isValidMove(char board[3][3], int move)
{
    if (move < 1 || move > 9)
        return false;

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    return (board[row][col] >= '1' && board[row][col] <= '9');
}

void makeMove(char board[3][3], int move, char symbol)
{
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = symbol;
}

bool checkWin(char board[3][3], char symbol)
{

    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) || 
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))  
        {
            return true;
        }
    }

    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
    {
        return true;
    }

    return false;
}

int main()
{
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int move;
    string player1, player2;

    cout << "Enter the name of Player 1: ";
    getline(cin, player1);
    player1 = toUpperCase(player1);

    cout << "Enter the name of Player 2: ";
    getline(cin, player2);
    player2 = toUpperCase(player2);

    printBoard(board);

    bool isPlayer1Turn = true;
    for (int turn = 0; turn < 9; turn++)
    {
        string currentPlayer = isPlayer1Turn ? player1 : player2;
        char symbol = isPlayer1Turn ? 'X' : 'O';

        while (true)
        {
            cout << currentPlayer << ",Your turn please enter your move between(1 -9): ";
            cin >> move;

            if (isValidMove(board, move))
            {
                break;
            }
            else
            {
                cout << "Invalid move! please try again..." << endl;
            }
        }

        makeMove(board, move, symbol);
        printBoard(board);

        if (checkWin(board, symbol))
        {
            cout << "CONGRATULATIONS, " << currentPlayer << "! YOU WIN" << endl;
            return 0;
        }

        isPlayer1Turn = !isPlayer1Turn;
    }

    cout << "Its Draw Bro --><-- " << endl;
    return 0;
}
