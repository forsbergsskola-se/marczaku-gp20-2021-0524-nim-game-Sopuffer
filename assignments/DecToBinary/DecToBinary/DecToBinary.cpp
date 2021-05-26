#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

/*Source: https://www.geeksforgeeks.org/program-decimal-binary-conversion/*/
void decToBinary(int n)
{
    int binaryNum[32];

    int i = 0;
    while (n > 0) {

        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    if (i == 1) {
        cout << "0b000";

    }
    else if (i < 3 && i > 1) {
        cout << "0b00";

    }
    else if (i < 4 && i > 2) {
        cout << "0b0";
    }
    else {
        cout << "0b";
    }
    for (int j = i - 1; j >= 0; j--)
        
        cout << binaryNum[j];
}

int main()
{
    cout << "Please enter a decimal number:" << endl;
    bool validInput = false;
    while (!validInput) {
        int  n;
        cin >> n;
        if (n < 0) {
            cout << "Cannot be a negative number. Please try again" << endl;
            continue;
        }
        else {
            decToBinary(n);
            validInput = true;
        }
        
    }
}
