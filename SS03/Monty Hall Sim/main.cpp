#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

void PrintMessage(string);
int GetMoneyDoor();
int GetPlayerInput();
void DrawDoors(char[]);
int GetHostChoice(int, int);
int GetOtherChoice(int, int);
char SwitchInput();
void RevealDoor(char[], int);
bool RevealWinner(int, int);
bool SwitchDoor();
void PrintStatistics(int, int, int[], bool);

int main()
{
	srand((unsigned int)time(0));

	string introMsg = "The Monty Hall Game Show!\n------------------------ ";
	PrintMessage(introMsg);


	int rounds = 0;
	int doorWins[3] = { 0, 0, 0 };
	int playerWins = 0;

	PrintMessage("How Many Rounds to Play? ");
	rounds = GetPlayerInput();

	PrintMessage("Switch Doors (y/n)?");
	char switchDoorsInput = SwitchInput();
	bool switchDoors = false;

	if (switchDoorsInput == 'Y' || switchDoorsInput == 'y')
	{
		switchDoors = true;
	}

	int roundsPlayed = 0;
	while (rounds > roundsPlayed)
	{
		char doors[3] = { '1', '2', '3' };

		int moneyDoor = GetMoneyDoor();

		DrawDoors(doors);
		PrintMessage("Which door does the player choose (1/2/3)? ");
		int playerDoor = GetMoneyDoor();
		PrintMessage(to_string(playerDoor + 1));

		//Host Pick Door
		int hostDoor = GetHostChoice(playerDoor, moneyDoor);

		PrintMessage("");
		string hostString = ("Game host choose door number ");
		hostString += to_string(hostDoor + 1);
		hostString += "...";
		PrintMessage(hostString);
		doors[hostDoor] = 'X';
		DrawDoors(doors);

		int otherDoor = GetOtherChoice(playerDoor, hostDoor);
		string otherString = ("Does the player want to switch from Door ");
		otherString += to_string(playerDoor+ 1);
		otherString += " to Door ";
		otherString += to_string(otherDoor + 1);
		otherString += "? (y/n)";
		PrintMessage(otherString);

		if (switchDoors)
		{
			PrintMessage("y");
			int temp = playerDoor;
			playerDoor = otherDoor;
			otherDoor = temp;
		}
		else
		{
			PrintMessage("n");
		}

		RevealDoor(doors, moneyDoor);

		bool playerWin = RevealWinner(playerDoor, moneyDoor - 1);

		if (playerWin)
		{
			PrintMessage("Congratulations! The player wins!");
			playerWins++;
		}
		else
		{
			PrintMessage("Oh no! The player lost!");
		}

		roundsPlayed++;
		doorWins[moneyDoor]++;
		Sleep(10);
	}

	PrintStatistics(roundsPlayed, playerWins, doorWins, switchDoors);
}

void PrintStatistics(int roundsPlayed, int playerWins, int doorWins[], bool switchDoors)
{
	PrintMessage("");
	PrintMessage("Game Statistics: ");
	PrintMessage("------------------");

	string roundsString = "Rounds Played: ";
	roundsString += to_string(roundsPlayed);
	PrintMessage(roundsString);
	
	string roundsWon = "Rounds Won: ";
	roundsWon += to_string(playerWins);
	PrintMessage(roundsWon);

	string roundsLost = "Rounds Lost: ";
	roundsLost += to_string(roundsPlayed - playerWins);
	PrintMessage(roundsLost);

	string switchingDoors = "Switching Doors: ";
	if (switchDoors)
	{
		switchingDoors += "true";
	}
	else
	{
		switchingDoors += "false";
	}
	PrintMessage(switchingDoors);
	
	for (int i = 0; i < 3; i++)
	{
		string doorWinString = "Door ";
		doorWinString += to_string(i + 1);
		doorWinString += ": ";
		doorWinString += to_string(doorWins[i]);
		PrintMessage(doorWinString);
	}

	PrintMessage("");
}

bool SwitchDoor()
{
	int switchDoor = (rand() % 2);

	if (switchDoor == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool RevealWinner(int playerDoor, int moneyDoor)
{
	if (playerDoor == moneyDoor)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void RevealDoor(char doors[], int moneyDoor)
{
	for (int i = 0; i < 3; i++)
	{
		if (i == moneyDoor)
		{
			doors[moneyDoor] = '$';
		}
		else
		{
			doors[i] = 'X';
		}
	}

	DrawDoors(doors);
}

char SwitchInput()
{
	bool valid = false;

	while (!valid)
	{
		char input = '\0';
		cin >> input;

		if (input != '\0')
		{
			if (input == 'y' || input == 'Y' || input == 'n' || input == 'N')
			{
				return input;
			}
		}
	}

	return '\0';
}

int GetOtherChoice(int playerDoor, int hostDoor)
{
	int otherDoor = -1;
	for (int i = 0; i < 3; i++)
	{
		if (i != playerDoor && i != hostDoor)
		{
			otherDoor = i;
			return otherDoor;
		}
	}

	return otherDoor;
}

int GetHostChoice(int playerDoor, int moneyDoor)
{
	if (playerDoor == moneyDoor)
	{
		int hostChoices[2];
		int index = 0;
		for (int i = 0; i < 3; i++)
		{
			if (i != playerDoor)
			{
				hostChoices[index] = i;
				index++;
			}
		}

		int hostChoiceRand = (rand() % 2);
		return hostChoices[hostChoiceRand];
	}
	else
	{
		int hostChoice = 0;
		for (int i = 0; i < 3; i++)
		{
			if (i != playerDoor && i != moneyDoor)
			{
				hostChoice = i;
			}
		}

		return hostChoice;
	}
}

void DrawDoors(char doors[])
{
	PrintMessage("");
	PrintMessage("Door1 Door2 Door3");
	PrintMessage("+---+ +---+ +---+");
	PrintMessage("|   | |   | |   |");

	string doorNumbers = "| ";
	doorNumbers += doors[0];
	doorNumbers += " | | ";
	doorNumbers += doors[1];
	doorNumbers += " | | ";
	doorNumbers += doors[2];
	doorNumbers += " |";
	
	PrintMessage(doorNumbers);
	PrintMessage("|   | |   | |   |");
	PrintMessage("+---+ +---+ +---+");
}

int GetPlayerInput()
{
	int playerDoor;
	cin >> playerDoor;

	return playerDoor;
}

int GetMoneyDoor()
{
	return (rand() % 3);
}

void PrintMessage(string message)
{
	cout << message << endl;
}