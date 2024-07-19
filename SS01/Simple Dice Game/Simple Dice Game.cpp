// Simple Dice Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <conio.h>

void aiturn(int&, int&);
void playerturn(int&, int&);
void printtext(int, int, bool);
bool checkwinner(int, int, int, int);


int main()
{
	//Set Random Timer
	srand((int)time(0));

	//Game Variables
	unsigned char key = '\0';
	bool playerTurn = true;

	int playerD1 = 0;
	int playerD2 = 0;

	int aiD1 = 0;
	int aiD2 = 0;

	//Game Loop
	do
	{
		if (playerTurn)
		{
			//Post Text
			std::cout << '\n' << "Press any key to roll... Press 'Q' to quit." << std::endl;

			//Get Key
			key = _getch();

			playerturn(playerD1, playerD2);
			aiturn(aiD1, aiD2);
		}
		else
		{
			aiturn(aiD1, aiD2);
			
			//Post Text
			std::cout << '\n' << "Press any key to roll... Press 'Q' to quit." << std::endl;
			
			//Get Input
			key = _getch();

			playerturn(playerD1, playerD2);
		}

		if (checkwinner(playerD1, playerD2, aiD1, aiD2))
		{
			std::cout << "\n" << "Player wins." << std::endl;
		}
		else 
		{
			std::cout << "\n" << "Ai wins." << std::endl;
		}
	} while (key != 'q' && key != 'Q');


	return 0;
}

//Check Winner 
bool checkwinner(int playerD1, int playerD2, int aiD1, int aiD2)
{
	//If player die are equal
	if (playerD1 == playerD2)
	{
		//If ai is also equal
		if (aiD1 == aiD2)
		{
			return ((playerD1 + playerD2) > (aiD1 + aiD2)) ? true : false;
		}
		else
		{
			return true;
		}
	}
	else if (aiD1 == aiD2) //If ai is equal, but player is not
	{
		return false;
	}

	//Else return highest sum
	return ((playerD1 + playerD2) > (aiD1 + aiD2)) ? true : false;
}

//For Player Turn
void playerturn(int& playerD1, int& playerD2)
{
	//Randomise Dice
	playerD1 = (rand() % 6) + 1;
	playerD2 = (rand() % 6) + 1;

	//Print Text
	printtext(playerD1, playerD2, true);

	return;
}

//Print Text for Turns
void printtext(int d1, int d2, bool player)
{
	//Check if Player
	if (player)
	{
		std::cout << "Player Turn: " << std::endl;
	}
	else
	{
		std::cout << "AI Turn: " << std::endl;
	}

	//Print Results
	std::cout << "Dice 1: \n";
	std::cout << d1;
	std::cout << "\n";
	std::cout << "Dice 2: \n";
	std::cout << d2;
	std::cout << "\n" << std::endl;
}

void aiturn(int& aiD1, int& aiD2)
{
	aiD1 = (rand() % 6) + 2;

	aiD2 = (rand() % 6) + 2;

	if (aiD1 != aiD2)
	{
		if (aiD1 < 6)
		{
			if (((rand() % 100) + 1) > 70)
			{
				aiD1++;
			}
		}

		if (aiD2 < 6)
		{
			if (((rand() % 100) + 1) > 70)
			{
				aiD2++;
			}
		}
	}
	else
	{
		if (aiD1 != 6)
		{
			if (((rand() % 100) + 1) > 70)
			{
				aiD1++;
				aiD2++;
			}
		}
	}

	printtext(aiD1, aiD2, false);

	return;
}