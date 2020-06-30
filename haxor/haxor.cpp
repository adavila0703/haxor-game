#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

void intro(int level) 
{
    cout << "Welcome! Figure out the 4 digits to win, lets see if you are a haxor!" << endl;
    cout << "You have 3 attempts to get it right." << endl;
    cout << "Format example when you enter your attempt-> X X X X" << endl; 
    cout << "\nLevel:" << level << endl;
}
bool game(int a) 
{
    int rannum1 = a + rand() % 2;
    int rannum2 = a + rand() % 2;
    int rannum3 = a + rand() % 2;
    int rannum4 = a + rand() % 2;
	int addednum = rannum1 + rannum2 + rannum3 + rannum4;
	int multinum = rannum1 * rannum2 * rannum3 * rannum4;
    int divnum = rannum1 * 2, ldivnum = rannum4 * 3, midnum = rannum2 % 2, lmidnum = rannum3 % 2;
    int num1, num2, num3, num4, lives = 4;
    bool ingame = true;


    cout << "\nNumbers add up to: " << addednum << "\nNumbers multiplied are: " << multinum << 
        "\nThe 1st number is 1/2 of: " << divnum << endl;
    if (midnum == 1)
    {
        cout << "The 2nd number is even." << endl;
    }
    else if (midnum == 0)
    {
        cout << "the 2nd number is odd." << endl;
    }
	if (lmidnum == 1)
	{
		cout << "The 3nd number is even." << endl;
	}
	else if (lmidnum == 0)
	{
		cout << "the 3nd number is odd." << endl;
	}
    cout <<"The 4th number is a 1/3 of: " << ldivnum << endl;

    while (ingame == true)
    {
        lives -= 1;
		cout << "\nYour Lives: " << lives << endl;
        if (lives > 0) 
        {
            cout << "Enter Your code ->";
			cin >> num1 >> num2 >> num3 >> num4;

			int guessadded = num1 + num2 + num3 + num4;
			int guessmulti = num1 * num2 * num3 * num4;

			if (addednum == guessadded && guessmulti == multinum)
			{
				ingame = false;
			}
			else
			{
				cout << "Try again.." << endl;
			}
        }
        else
        {
            ingame = false;
        }
    }

	if (lives < 1)
	{
        cout << "false" << endl;
		return false;
	}
	else
	{
        cout << "true" << endl;
		return true;
	}

}

int main()
{

    srand(time(NULL));

    int level = 1;
    int maxlevel = 1000000;
    bool gamestatus = true;
    
    while (gamestatus == true)
    {
        intro(level);
        gamestatus = game(level);
		level++;
        cout << gamestatus << endl;
		system("CLS");
    }

    cout << "Game Over! Your max level was " << level << endl;

    return NULL;    
}