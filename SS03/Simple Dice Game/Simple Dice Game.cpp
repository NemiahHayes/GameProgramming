// Simple Dice Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <random>

#define DEBUG

void aiturn(int&, int&, int, int);
void playerturn(int&, int&);
void printtext(int, int, bool);
void CheckWinner(int, int, int, int, int&, int&, int&);
bool IsDouble(int, int);
int BiasedRoll();
void PrintStatistics(int, int, int, int);


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

	int playerwins = 0;
	int aiwins = 0;
	int draws = 0;
	int rounds = 0;

	std::cout << "How Many Rounds to Play? ";

	std::cin >> rounds;
	int roundsPlayed = 0;
	//Game Loop
	do
	{
		if (playerTurn)
		{
#ifndef DEBUG
			//Post Text
			std::cout << '\n' << "Press any key to roll... Press 'Q' to quit." << std::endl;
			//Get Key
			key = _getch();
#endif
			playerturn(playerD1, playerD2);
			aiturn(aiD1, aiD2, playerD1, playerD2);
		}
		else
		{
			aiturn(aiD1, aiD2, playerD1, playerD2);
#ifndef DEBUG
			//Post Text
			std::cout << '\n' << "Press any key to roll... Press 'Q' to quit." << std::endl;
			
			//Get Input
			key = _getch();
#endif
			playerturn(playerD1, playerD2);
		}

		CheckWinner(playerD1, playerD2, aiD1, aiD2, playerwins, aiwins, draws);
		roundsPlayed++;
	} while (roundsPlayed <= rounds || (key == 'q' || key == 'Q'));
		
#ifdef DEBUG
	std::cout << "\nGame Statistics: \n";
	PrintStatistics((playerwins + aiwins + draws), playerwins, aiwins, draws);
#endif
	return 0;
}

void PrintStatistics(int rounds, int playerWins, int aiWins, int draws)
{
#ifdef DEBUG
	double playerWinPercentage = (static_cast<double>(playerWins) / rounds) * 100.0;
	double aiWinPercentage = (static_cast<double>(aiWins) / rounds) * 100.0;
	double drawPercentage = (static_cast<double>(draws) / rounds) * 100.0;
	std::cout << "Player Win % : " << playerWinPercentage << "%" << std::endl;
	std::cout << "AI Win % : " << aiWinPercentage << "%" << std::endl;
	std::cout << "Draw % : " << drawPercentage << "%" << std::endl;
#endif
}

//Check Winner 
void CheckWinner(int playerD1, int playerD2, int aiD1, int aiD2, int& playerwins, int& aiwins, int& draws)
{
	bool player = false;
	bool ai = false;
	//If player die are equal
	if (IsDouble(playerD1, playerD2) && IsDouble(aiD1, aiD2)) // Both Double
	{
		if (playerD1 > aiD1)
		{
			player = true;
		}
		else if (aiD1 > playerD1)
		{
			ai = true;
		}
	}
	else if (IsDouble(playerD1, playerD2)) // Player Double
	{
		player = true;
	}
	else if (IsDouble(aiD1, aiD2)) //AI Double
	{
		ai = true;
	}
	else // Highest SUm
	{
		int playersum = playerD1 + playerD2;
		int aisum = aiD1 + aiD2;
		if (playersum > aisum)
		{
			player = true;
		}
		else if (playersum < aisum)
		{
			ai = true;
		}
	}

	if (player)
	{
		std::cout << "Player Wins!" << std::endl;
		playerwins++;
	}
	else if (ai)
	{
		std::cout << "AI Wins!" << std::endl;
		aiwins++;
	}
	else
	{
		std::cout << "Draw!" << std::endl;
		draws++;
	}
	PrintStatistics((playerwins + aiwins + draws), playerwins, aiwins, draws);
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

void aiturn(int& aiD1, int& aiD2, int playerD1, int playerD2)
{
	bool aiWinCheck = rand() % 100 < 50 ? true : false;

	if (aiWinCheck)
	{
		if (!IsDouble(playerD1, playerD2))
		{
			aiD1 = aiD2 = BiasedRoll();
		}
		else
		{
			if (playerD1 < 6)
			{
				aiD1 = aiD2 = playerD1 + 1;
			}
			else
			{
				aiD1 = aiD2 = 6;
			}
		}
	}
	else
	{
		aiD1 = BiasedRoll();
		aiD2 = BiasedRoll();
	}

	printtext(aiD1, aiD2, false);

	return;
}

bool IsDouble(int d1, int d2)
{
	return d1 == d2;
}

int BiasedRoll() {
	int outcome = rand() % 100;
	if (outcome < 15)
	{
		return 1;
	}
	else if (outcome < 35)
	{
		return 2;
	}
	else if (outcome < 55)
	{
		return 3;
	}
	else if (outcome < 65)
	{
		return 4;
	}
	else if (outcome < 85)
	{
		return 5;
	}
	else 
	{
		return 6;
	}
}