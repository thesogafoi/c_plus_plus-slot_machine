#include <iostream>
#include<math.h>
#include <ctime>
#include <cstdlib>
    using namespace std;

    int Random(int min , int max);
    bool checkIfTwoNumbersEqual(int x,int  y,int  z);
    int chips;
    bool play;
    bool exitApp;
    int betNumber;
    bool validBetNumber = false;
int main()
{
    chips = 1000;
    play = false;
    exitApp = true;
    do
    {
        cout << "Player Chips is : " << chips << "$" << endl;
        cout << "1) Play slot . 2) exit" << endl;
        int exitNumber;
        cin >> exitNumber;
            if (exitNumber== 2) {
                play = false;
                exitApp = true;
            }
            else if (exitNumber== 1) {
                play = true;
                exitApp = false;
            }
            else {
                cout << "Choose right number for play game or exit";
                exitApp = false;
            }
            if (play) {
                srand(time(0));
                while (!validBetNumber) {
                        cout << "Enter your Bet " << endl;
                        cin >> betNumber;
                        if (betNumber > chips || betNumber <= 0) {
                            cout << "Please Enter Valid Bet Number";
                        }
                        else {
                            validBetNumber = true;
                        }
                   }
                    int x, y, z;
                    x = Random(2, 7);
                    y = Random(2,7);
                    z = Random(2,7);
                    int winChips;
                    cout << "Choosed Numbers are : " << x << " , "<< y  <<  " , "  << z   << endl;
                    if (x== 7 && y == 7 && z == 7) {
                        winChips = betNumber * 10;
                        cout << "WOW greatly win " << endl;
                    }
                    else if (x == y && y == z && x != 7) {
                        winChips = betNumber * 5;
                        cout << "wow nice win" << endl;
                    }
                    else if (checkIfTwoNumbersEqual(x,y,z)) {
                        winChips = betNumber * 3;
                        cout << "you win ! " << endl;
                    }
                    else {
                        winChips = 0;
                        cout << "Sorry you loose" << endl;
                    }
                    chips -= betNumber;
                    validBetNumber = false;
                    chips += winChips;
                }
                if (chips == 0) {
                    play = false;
                    exitApp = true;
                    cout << "Your chips is not enough" << endl;
                }
            
    } while (!exitApp);
    cout << "thank you for played slot ! " << endl;
    return 0;
}

int Random(int min , int max) {
    return min + rand() % (max - min);
}

bool checkIfTwoNumbersEqual(int x,int  y,int  z) {
    if (x== z || z==y || x==y) {
        return true;
    }
    return false;
}
