// NimGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
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

void DeclareWinnerAI(bool FirstPlayer) {
    if (FirstPlayer) {
        cout << "AI Player wins" << endl;
    }
    else {
        cout << "Congratulations! You win!" << endl;

    }
}
void DeclareWinnerTwoPlr(bool FirstPlayer) {
    if (FirstPlayer) {
        cout << "Player 2 wins" << endl;
    }
    else {
        cout << "Player 1 wins" << endl;

    }
}

void StartTwoPlrNimGame(int matches, char visualMatch) {
    bool winner = false;
    bool firstPlayer = true;
    vector<char> v;
    v.resize(matches, visualMatch);
    cout << "This is the assigned amount of matches:" << endl;
    cout << "Amount: " << matches << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl << endl;
    cout << "Lets start the game!" << endl;

    while (!winner) {
        if (firstPlayer) {
            cout << "Amount of matches left: " << v.size() << endl;
            cout << "Player 1, Choose a number of matches to remove between 1-3" << endl;

            string response;
            cin >> response;

            if (Check_number(response)) {
                int results = stoi(response);

                if (results < 1 || results > 3) {
                    cout << "This is an invalid amount of matches. Cannot be less than 1. Cannot be more than 3. Please try again." << endl;
                    continue;
                }
                else {
                    matches = matches - results;
                    if (matches > v.size()) {
                        v.resize(0, visualMatch);
                    }
                    else {

                        v.resize(matches, visualMatch);
                    }

                    if (v.size() <= 0) {
                        winner = true;
                        DeclareWinnerTwoPlr(firstPlayer);

                    }
                    else {
                        cout << matches << " matches left" << endl;
                        for (int i = 0; i < v.size(); ++i) {
                            cout << v[i] << " ";
                        }
                        cout << endl << endl;
                        firstPlayer = true;
                        continue;
                    }
                    
               
                }
            }
        }
        else {
            cout << "Amount of matches left: " << v.size() << endl;
            cout << "Player 2, Choose a number of matches to remove between 1-3" << endl;

            string response;
            cin >> response;

            if (Check_number(response)) {
                int results = stoi(response);

                if (results < 1 || results > 3) {
                    cout << "This is an invalid amount of matches. Cannot be less than 1. Cannot be more than 3. Please try again." << endl;
                    continue;
                }
                else {
                    matches = matches - results;
                    if (matches > v.size()) {
                        v.resize(0, visualMatch);
                    }
                    else {

                        v.resize(matches, visualMatch);
                    }

                    if (v.size() <= 0) {
                        winner = true;
                        DeclareWinnerTwoPlr(firstPlayer);

                    }
                    else {
                        cout << matches << " matches left" << endl;
                        for (int i = 0; i < v.size(); ++i) {
                            cout << v[i] << " ";
                        }
                        cout << endl << endl;
                        firstPlayer = true;
                        continue;
                    }
                }
           
                
            }

        }
    }
}


void StartAINimGame(int matches, char visualMatch) {
    bool winner = false;
    bool firstPlayer = true;
    vector<char> v;
    v.resize(matches, visualMatch);
    cout << "This is the assigned amount of matches:" << endl;
    cout << "Amount: " << matches << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl << endl;
    cout << "Lets start the game!" << endl;

    while (!winner) {
        cout << "Amount of matches left: " << v.size() << endl;
        cout << "Choose a number of matches to remove between 1-3" << endl;
   
        if (firstPlayer) {
            string response;
            cin >> response;

            if (Check_number(response)) {
                int results = stoi(response);
                
                if (results < 1 || results > 3) {
                    cout << "This is an invalid amount of matches. Cannot be less than 1. Cannot be more than 3. Please try again." << endl;
                    continue;
                }
                else {
                    matches = matches - results;
                    if (matches > v.size()) {
                        v.resize(0, visualMatch);
                    }
                    else {

                        v.resize(matches, visualMatch);
                    }

                    if (v.size() <= 0) {
                        winner = true;
                        DeclareWinnerAI(firstPlayer);

                    }
                    else {
                        cout << matches << " matches left" << endl;
                        for (int i = 0; i < v.size(); ++i) {
                            cout << v[i] << " ";
                        }
                        cout << endl << endl;
                        firstPlayer = false;
                        continue;
                    }
                }
                
            }
            
        }
        else {
            if (v.size() > 3) {
                int aiMatches = rand() % 3 + 1;
                matches = matches - aiMatches;

                v.resize(matches, visualMatch);
            }
            else {
                if (v.size() == 3) {
                    int aiMatches = rand() % 2 + 1;
                    matches = matches - aiMatches;

                    v.resize(matches, visualMatch);
                }
                else {
                    int aiMatches = 1;
                    matches = matches - aiMatches;

                    v.resize(matches, visualMatch);
                }
                
            }
    
            if (v.size()<= 0) {
                winner = true;
                DeclareWinnerAI(firstPlayer);
            }

            else {
                cout << matches << " matches left" << endl;
                for (int i = 0; i < v.size(); ++i) {
                    cout << v[i] << " ";
                }
                cout << endl << endl;
                firstPlayer = true;
                continue;
            }
        }

    }
}
int main()
{
    bool validInput = false;
    string answer;
    char visualMatch = '|';
    int matches;
    while (!validInput) {
        cout << "Please enter the amount of matches (6-30) you would like to play NimGame with: " << endl;
        cin >> answer;
        if (Check_number(answer)) {
            int results = stoi(answer);

            if (results < 6 || results > 30) {
                cout << "This is an invalid amount of matches. Cannot be less than 6. Cannot be more than 30. Please try again." << endl;
                continue;
            }
            else {
                validInput = true;
                matches = results;
            }
        }
        else {
            cout << "This is an invalid answer. Please try again." << endl;
            continue;
        }
    }
    if (validInput) {
        bool chosenMatchType = false;
        while (!chosenMatchType) {
            cout << "Want to play against another Player or against an AI? Choose between 0-1" << endl;
            cout << "0: Two Players" << endl;
            cout << "1: AI Player" << endl;
            string answer;
            int choice;
            cin >> answer;
            if (Check_number(answer)) {
                choice = stoi(answer);
                if (choice != 0 && choice != 1) {
                    cout << "This is an invalid answer. Please try again." << endl;
                    continue;
                }
                else {
                    switch (choice) {
                    case 0:
                        StartTwoPlrNimGame(matches, visualMatch);
                        break;
                    case 1:
                        StartAINimGame(matches, visualMatch);
                        break;
                    }
                    chosenMatchType = true;
                }
            }
            else {
                cout << "This is an invalid answer. Please try again." << endl;
                continue;
            }
        }
     
   }

}

