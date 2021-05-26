
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

void StartGame() {
    char square1('1');
    char square2('2');
    char square3('3');
    char square4('4');
    char square5('5');
    char square6('6');
    char square7('7');
    char square8('8');
    char square9('9');
    bool gameOver(true);
    int playerTurn(1);
    do {
        cout << square1 << "|" << square2 << "|" << square3 << endl;
        cout << "-+-+-" << endl;
        cout << square4 << "|" << square5 << "|" << square6 << endl;
        cout << "-+-+-" << endl;
        std::cout << square7 << "|" << square8 << "|" << square9 << std::endl;

        char playerMark;

        if (playerTurn == 1) {
            playerMark = 'X';
        }
        else {
            playerMark = 'O';
        }

        cout << "Player" << playerTurn << "'s move:" << endl;
        bool validMove;
        do {
            char nextMove;
            std::cin >> nextMove;
            validMove = true;

            if (nextMove == '1' && square1 == '1') {
                square1 = playerMark;
            }
            else if (nextMove == '2' && square2 == '2') {
                square2 = playerMark;
            }
            else if (nextMove == '3' && square3 == '3') {
                square3 = playerMark;
            }
            else if (nextMove == '4' && square4 == '4') {
                square4 = playerMark;
            }
            else if (nextMove == '5' && square5 == '5') {
                square5 = playerMark;
            }
            else if (nextMove == '6' && square6 == '6') {
                square6 = playerMark;
            }
            else if (nextMove == '7' && square7 == '7') {
                square7 = playerMark;
            }
            else if (nextMove == '8' && square8 == '8') {
                square8 = playerMark;
            }
            else if (nextMove == '9' && square9 == '9') {
                square9 = playerMark;
            }
            else {
                cout << "Invalid Move. Try again." << endl;
                validMove = false;
            }
        } while (!validMove);

        gameOver = false;
        bool winGame = true;

        if (square1 != '1') {
            if (square2 == square1 && square3 == square1) {
                gameOver = true;
            }
            if (square4 == square1 && square7 == square1) {
                gameOver = true;
            }
        }
        if (square5 != '5') {
            if (square1 == square5 && square9 == square5) {
                gameOver = true;
            }
            if (square2 == square5 && square8 == square5) {
                gameOver = true;
            }
            if (square4 == square5 && square6 == square5) {
                gameOver = true;
            }
            if (square3 == square5 && square7 == square5) {
                gameOver = true;
            }
        }
        if (square9 != '9') {
            if (square3 == square9 && square6 == square9) {
                gameOver = true;
            }
            if (square7 == square9 && square8 == square9) {
                gameOver = true;
            }
        }

        if (square1 != '1' && square2 != '2' && square3 != '3' &&
            square4 != '4' && square5 != '5' && square6 != '6' &&
            square7 != '7' && square8 != '8' && square9 != '9' && gameOver)
        {
            gameOver = true;
            winGame = false;
        }
        if (gameOver) {
            if (winGame) {
                cout << "Player" << playerTurn << " wins!" << endl;
            }

            cout << square1 << "|" << square2 << "|" << square3 << endl;
            cout << "-+-+-" << endl;
            cout << square4 << "|" << square5 << "|" << square6 << endl;
            cout << "-+-+-" << endl;
            cout << square7 << "|" << square8 << "|" << square9 << endl;

            cout << "Game Over!" << endl;
            cout << "Play again (y/n)?" << endl;
            char cPlayAgain;
            cin >> cPlayAgain;

            if (cPlayAgain == 'y') {
                gameOver = false;
                square1 = '1';
                square2 = '2';
                square3 = '3';
                square4 = '4';
                square5 = '5';
                square6 = '6';
                square7 = '7';
                square8 = '8';
                square9 = '9';
            }
            playerTurn = 1;
        }
        else {
            if (playerTurn == 1) {
                playerTurn = 2;
            }
            else {
                playerTurn = 1;
            }
        }
    }while (!gameOver);
}

int main()
{
    StartGame();
}



