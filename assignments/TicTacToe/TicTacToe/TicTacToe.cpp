
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

bool Check_number(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}


void TicTacToeAI() {
    string square1("1");
    string square2("2");
    string square3("3");
    string square4("4");
    string square5("5");
    string square6("6");
    string square7("7");
    string square8("8");
    string square9("9");
    bool gameOver(true);
    int playerTurn(1);
    bool aiPlayer = false;
    do {
        cout << square1 << "|" << square2 << "|" << square3 << endl;
        cout << "-+-+-" << endl;
        cout << square4 << "|" << square5 << "|" << square6 << endl;
        cout << "-+-+-" << endl;
        std::cout << square7 << "|" << square8 << "|" << square9 << std::endl;

        string playerMark;

        if (playerTurn == 1) {
            playerMark = "X";
            aiPlayer = false;
        }
        else {
            playerMark = "O";
            aiPlayer = true;
        }

        cout << "Player" << playerTurn << "'s move:" << endl;
        

        bool validMove;

        do {
             
                string nextMove;
                if (!aiPlayer) {
                    std::cin >> nextMove;
                }
                else {
                    const int maxNumber = 9;
                    char aiMoveChoices[maxNumber] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
                    for (int i = 0; i < maxNumber; i++)
                    {
                        nextMove = "";
                        nextMove = nextMove + aiMoveChoices[rand() % maxNumber];
                    }
                }
                validMove = true;

                if (nextMove == "1" && square1 == "1") {
                    square1 = playerMark;
                }
                else if (nextMove == "2" && square2 == "2") {
                    square2 = playerMark;
                }
                else if (nextMove == "3" && square3 == "3") {
                    square3 = playerMark;
                }
                else if (nextMove == "4" && square4 == "4") {
                    square4 = playerMark;
                }
                else if (nextMove == "5" && square5 == "5") {
                    square5 = playerMark;
                }
                else if (nextMove == "6" && square6 == "6") {
                    square6 = playerMark;
                }
                else if (nextMove == "7" && square7 == "7") {
                    square7 = playerMark;
                }
                else if (nextMove == "8" && square8 == "8") {
                    square8 = playerMark;
                }
                else if (nextMove == "9" && square9 == "9") {
                    square9 = playerMark;
                }
                else {
                    cout << "Invalid Move. Try again." << endl;
                    validMove = false;
                }
             
        } while (!validMove);

        gameOver = false;
        bool winGame = true;

        if (square1 != "1") {
            if (square2 == square1 && square3 == square1) {
                gameOver = true;
            }
            if (square4 == square1 && square7 == square1) {
                gameOver = true;
            }
        }
        if (square5 != "5") {
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
        if (square9 != "9") {
            if (square3 == square9 && square6 == square9) {
                gameOver = true;
            }
            if (square7 == square9 && square8 == square9) {
                gameOver = true;
            }
        }

        if (square1 != "1" && square2 != "2" && square3 != "3" &&
            square4 != "4" && square5 != "5" && square6 != "6" &&
            square7 != "7" && square8 != "8" && square9 != "9" && gameOver)
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
            bool validInput = false;
            while (!validInput) {
                cout << "Play again (y/n)?" << endl;
                char playAgain;
                cin >> playAgain;

                if (playAgain == 'y') {
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
                    validInput = true;
                }
                else {
                    if (playAgain != 'n') {
                        cout << "Invalid input. Please Try again." << endl;
                        continue;
                    }
                    else {
                        validInput = true;
                    }
                }
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
    } while (!gameOver);
}

void TicTacToeTwoPlr() {
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
            bool validInput = false;
            while (!validInput) {
                cout << "Play again (y/n)?" << endl;
                char playAgain;
                cin >> playAgain;

                if (playAgain == 'y') {
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
                    validInput = true;
                }
                else {
                    if (playAgain != 'n') {
                        cout << "Invalid input. Please Try again." << endl;
                        continue;
                    }
                    else {
                        validInput = true;
                    }
                }
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

void Introduction() {
    cout << "Welcome to TicTacToe! How would you like to play?" << endl;
    cout << "(0) Two Players" << endl;
    cout << "(1) AI Player" << endl;

    bool validInput = false;
    while (!validInput) {
        string answer;
        cin >> answer;
        if (Check_number(answer)) {
            int result = stoi(answer);
            if (result != 0 && result != 1) {
                cout << "Invalid answer. Please try again." << endl;
                continue;
            }
            else {
                switch (result) {
                case 0:
                    TicTacToeTwoPlr();
                    break;
                case 1:
                    TicTacToeAI();
                    break;
                }
                validInput = true;
            }
        }
        else {
            cout << "Invalid answer. Please try again." << endl;
            continue;
        }
    }
}

int main()
{
    Introduction();
}



