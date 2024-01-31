//Tic Tac Toe Game in C++
//Importing the inbuild libraries in CPP
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <string>
using namespace std;

//Game Variable Declaration
int game = 0;
//Array for the board
char board[9] = { '1','2','3','4','5','6','7','8','9' };
char disp[9];
int player = 1;
int choice;
char mark = 'X';

//Function to show the current status of the gaming board

void draw_board(int type) {

    //Rander Game Board LAYOUT based on type
    if (type == 0) {
        for (int i = 0; i <= 7; i += 3) {
            if (i == 0) {
                cout << "     |     |     \n";
            }
            cout << "  " << board[i] << "  |  " << board[i + 1] << "  |  " << board[i + 2] << "\n";
            if (i != 6) {
                cout << "_____|_____|_____\n";
                cout << "     |     |     \n";
            }
            else {
                cout << "     |     |     \n";
            }
        }
    }
    else if (type == 1) {
        for (int i = 0; i <= 9; i++) {
            if (board[i] == 'X') {
                disp[i] = 'X';
            }
            else if (board[i] == 'O') {
                disp[i] = 'O';
            }
            else {
                disp[i] = ' ';
            }
        }
        for (int i = 0; i <= 7; i += 3) {
            if (i == 0) {
                cout << "     |     |     \n";
            }
            cout << "  " << disp[i] << "  |  " << disp[i + 1] << "  |  " << disp[i + 2] << "\n";
            if (i != 6) {
                cout << "_____|_____|_____\n";
                cout << "     |     |     \n";
            }
            else {
                cout << "     |     |     \n";
            }
        }
    }

}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

int gamestate(int res) {

    // Check if possible game win

    if (board[0] == board[1] && board[1] == board[2] ||
        board[3] == board[4] && board[4] == board[5] ||
        board[6] == board[7] && board[7] == board[8] ||
        board[0] == board[3] && board[3] == board[6] ||
        board[1] == board[4] && board[4] == board[7] ||
        board[2] == board[5] && board[5] == board[8] ||
        board[0] == board[4] && board[4] == board[8] ||
        board[2] == board[4] && board[4] == board[6]) {
        cout << "WIN";
        return 1;
    }

    // Check for draw
    for (int i = 0; i <= 8; i++) {
        if (board[i] == 'X' || board[i] == 'O') {
            res += 1;
        }
    }

    if (res == 9) {
        cout << "DRAW";
        return 2;
    }
}

//Program Main Method

int main()
{
    cout << "\nTic Tac Toe - Designed by ZS Productions\n";
    cout << "Player 1 [X] --- Player 2 [O]\n\n";
    cout << "Loading Game...\n\n";
    chrono::seconds start_delay(2);
    this_thread::sleep_for(start_delay);

    while (true) { // Loop until game finishes
        system("CLS");
        cout << "\nTic Tac Toe - Designed by ZS Productions\n";
        cout << "Player 1 [X] --- Player 2 [O]\n\n";
        draw_board(0);

        //Change player based on turn
        if (player % 2 != 0) {
            cout << "\nPlayer 1's Turn\n";
            mark = 'X';
        }
        else {
            cout << "\nPlayer 2's Turn\n";
            mark = 'O';
        }


        //Obtain player choice and check if valid
        while (true) {
            cout << "Enter the position between [1-9] where you want to mark: ";
            cin >> choice;
            if (cin.fail()) {
                cin.clear(); // clear fail flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (choice <= 0 || choice >= 10) {
                cin.clear(); // clear fail flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (board[choice - 1] == 'X' || board[choice - 1] == 'O') {
                cin.clear(); // clear fail flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.clear(); // clear fail flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            break;
        }

        board[choice - 1] = mark;
        player++;

        game = gamestate(0);

        system("CLS");
        cout << "\nTic Tac Toe - Designed by ZS Productions\n";
        cout << "Player 1 [X] --- Player 2 [O]\n\n";
        draw_board(1);
        chrono::seconds draw_delay(1);
        this_thread::sleep_for(draw_delay);

        if (game == 2) {
            cout << "Game Draw";
            break;
        }
        else if (game == 1) {
            player--;
            if (player % 2 != 0) {
                cout << "Player 1 Wins!";
            }
            else {
                cout << "Player 2 Wins!";
            }
            break;
        }
    }
}