//Program Name: Sorry_v3.cpp
//Program Author: Thomas Chandler
//Date last Updated: 12/20/2019
//Purpose: Play the board game Sorry!!!


#include <iostream>
#include <cmath>
#include <cstdlib>
#include<time.h>
#include <windows.h>
#include <string>
#include <algorithm>

using namespace std;

int randomNumber1();
int randomNumber2();
bool checkWinner(int);
int eleven(int, int);
int seven(int, int);
void check(int,int);
int *playerPosition;
int *f;

int main()

{
    
    int numberPlayers;
    
    int numbers;

    int k = 0;

    int j = 0;

    bool choice = true;

    while(choice)

    {

        cout <<"Enter number of players (2-4)";

        cin >> numberPlayers;

  

  

        while (numberPlayers < 2 || numberPlayers > 4)

        {

            cout << "Please enter a valid number " << endl;

            cin >> numberPlayers;

        }

  

        playerPosition =new int[numberPlayers];

        f =new int[numberPlayers];

  

        for (int i = 0; i < numberPlayers; i++)

        {

            playerPosition[i] = 0;

            f[i] = 0;

        }

        bool win = false;

        int winner;

  

        while(!win)

        {

            for (int j = 0; j < numberPlayers; j++)

            {
                string temp;

                cout << "\n\n\t\tPlayer " << j + 1 << ". " << "Hit ENTER to roll the dice: " << endl;
                getline(cin, temp);

                Sleep(1000);

                cout << "\n\n\t\tPlayer: " << j + 1 << " rolls the dice." << endl;

                int random1 = randomNumber1();

                int random2 = randomNumber2();

                numbers = random1 + random2;

                if (random1 == random2)

                {

                    f[j] = 1;

                }

                if (f[j] == 1)

                {

                    switch (numbers)

                    {

                        case 2:

                        if (playerPosition[j] + 2 <= 50)

                        playerPosition[j] += 2;

						break;

                        
						case 3:

                        if (playerPosition[j] + 3 <= 50)

                        playerPosition[j] += 3;

                        break;

                

                        case 4:

                        if (playerPosition[j] - 1 >=0)

                        playerPosition[j] -= 1;

                        else

                        {

                            playerPosition[j] = 0;

                            f[j] = 0;

                         }

                        break;

                

                        case 5:

                        if (playerPosition[j] + 5 <= 50)

                        playerPosition[j] += 5;

                        break;

                

                        case 6:

                        if (playerPosition[j] + 6 <= 50)

                        playerPosition[j] += 6;

                        break;

                

                        case 7:

                        if (playerPosition[seven(j, numberPlayers)] > playerPosition[j])
                        {
                            swap(playerPosition[j], playerPosition[seven(j, numberPlayers)]);

                            cout << "\n\n\t\tPlayer " << j + 1 << " swapped positions." << endl;
                        }                    
                        
                        break;

                

                        case 8:

                        if (playerPosition[j] + 8 <= 50)

                        playerPosition[j] += 8;

                        break;

                        
                        case 9:

                        if (playerPosition[j] - 1 > 0)

                            playerPosition[j] -= 1;

                        else

                        {

                            playerPosition[j] = 0;

                            f[j] = 0;

                        }

                        break;

                

                        case 10:

                        if (playerPosition[j] + 10 <=50)

                            playerPosition[j] += 10;

                        break;

                        case 11:

                        if (playerPosition[j] > playerPosition[eleven(j, numberPlayers)])
                        {
                            swap(playerPosition[j], playerPosition[eleven(j, numberPlayers)]);

                            cout << "\n\n\t\tPlayer " << j + 1 << " swapped positions." << endl;
                        }
                        break;

                

                        case 12:

                        playerPosition[j] = 0;

                        f[j] = 0;

                        break;

                    }

                    if (checkWinner(playerPosition[j]))

                    {

                        win = true;

                        winner = j + 1;

                        break;

                    }

                    Sleep(1000);

                    if (playerPosition[j] != 0)

                        check(j,numberPlayers);

                }

                    else

                        cout << "\n\n\t\tPlayer " << j + 1 <<" failed to roll a double:";

                        Sleep(1000);

                        cout << "\n\n\t\t Player " << j + 1 << " rolled a  " << random1 << " and a " << random2 << ". Current player positions are:\n\n";

                    for (int i = 0; i < numberPlayers; i++)

                    {

                        cout << "\t\tPlayer " << i + 1 << ":" << playerPosition[i] << endl;

                    }

            }

        }

        

        cout <<"\n\n==================================================================================" << endl;

        cout << "\n\n\t\tThe winner is: Player " << winner << endl;

        cout <<"==================================================================================" << endl;

        char c;

        cout << "\n\nWant to play Again (Y?N):" ;

        cin>>c;

        if (toupper(c)=='N')

        choice = false;

    }

    return 0;

}

int randomNumber1()

{

    int x, minNum = 1, maxNum = 6;

    unsigned seed;

    seed = time(0);

    srand(seed);

    x = rand() % (maxNum - minNum + 1) + minNum;

    return x;

    

}

int randomNumber2()

{

    int x, minNum = 1, maxNum = 6;

    //unsigned seed;

    //seed = time(0);

    //srand(seed);

    x = rand() % (maxNum - minNum + 1) + minNum;

    return x;

    

}

bool checkWinner(int i)

{

    if (i == 50)

        return true;

    else

        return false;

}

int seven(int j, int listSize)
{

    int maxIndex = 0;

    for (int index = 0; index < listSize; index++)

        if (index != j && playerPosition[index] > playerPosition[maxIndex])
            maxIndex = index;

    return maxIndex;






}

int eleven(int j, int listSize)
{
    int maxIndex = 0;

    for (int index = 0; index < listSize; index++)
    
        if (index != j && playerPosition[index] < playerPosition[maxIndex] && playerPosition[index] > 0)                          
        maxIndex = index;


    return maxIndex;               


}


void check(int player,int totalPlayer)
{

    int playerposition = playerPosition[player];

    for (int k = 0; k < totalPlayer; k++)

    {

        if (k != player && playerposition == playerPosition[k])

        {

            cout << "\n\n\t\tSorry!!!! Player " << player + 1 << " landed on player " << k + 1 << " so player " << k + 1 << " goes back to start!!" ;

            playerPosition[k] = 0;

            f[k] = 0;

        }

    }

}