#include <iostream>
#include <string>

using namespace std;

void AISpeak(string);
void AISpeakLetters(char);
char GetRandomLetter();
char GetPlayerInput();
bool GetPlayerResult(char, char, int);
bool GetPlayAgain();
void GoodbyeMsg(int);

int main()
{
	srand((int)time(0));
	bool playing = true;

	cout << "BUZZ, HUM, ZAP... Powering up the AI-Bot..." << endl;
	AISpeak("Welcome to \"The \'Basic\' Letter Guessing Game\"!");
	int rounds = 1;

	while (playing)
	{
		int turn = 1;
		bool won = false;
		char letter;
		
		letter = GetRandomLetter();
		AISpeakLetters(letter);
		AISpeak("I'm thinking of a secret letter, can you guess it...");

		while (!won)
		{
			string aiTurnText = "Turn " + to_string(turn) + ", what is your guess ? ";
			AISpeak(aiTurnText);
			char guess = GetPlayerInput();

			won = GetPlayerResult(guess, letter, turn);

			if (won)
			{
				AISpeak("Play Again (y/n)? ");
				bool playAgain = GetPlayAgain();

				if (!playAgain)
				{
					playing = false;

					GoodbyeMsg(rounds);
				}
			}
			else
			{
				turn++;
			}
		}
		rounds++;
	}

	cout << "Powering down the AI - Bot... FIZZ, POP, BANG!";
	return 0;
}

void GoodbyeMsg(int rounds)
{
	string aiGoodbye = "Thanks for playing " + to_string(rounds) + " round";
	if (rounds > 1)
	{
		aiGoodbye += "s";
	}
	aiGoodbye += " with me!";

	AISpeak(aiGoodbye);

	char goodbye[14] = { 'G', 'o', 'o', 'd', 'b', 'y', 'e', ' ', 'H', 'u', 'm', 'a', 'n', '!' };
	for (int i = 0; i < 14; i++)
	{
		string aiString = "";

		for (int j = 0; j < i; j++)
		{
			aiString += " ";
		}
		aiString += goodbye[i];
		AISpeak(aiString);
	}
}

bool GetPlayAgain()
{
	bool valid = false;
	while (!valid)
	{
		char playAgain = GetPlayerInput();

		if (playAgain == 'y' || playAgain == 'Y')
		{
			return true;
		}
		else if (playAgain == 'n' || playAgain == 'N')
		{
			return false;
		}

	}
}

bool GetPlayerResult(char guess, char letter, int turns)
{
	if (guess == letter)
	{
		AISpeak("Well Done!");
		string aiCongrats = "You took " + to_string(turns) + " turn";
		
		if (turns > 1)
		{
			aiCongrats += "s";
		}

		aiCongrats += "! Game Over!";

		AISpeak(aiCongrats);
		return true;
	}
	else
	{
		string aiWinText = "Wrong... my secret letter comes ";
		if (guess < letter)
		{
			aiWinText += "after ";
		}
		else
		{
			aiWinText += "before ";
		}

		aiWinText += guess;
		aiWinText += " in the Alphabet...";

		AISpeak(aiWinText);

		return false;
	}
}

char GetPlayerInput()
{
	char guess;
	std::cout << "Human: ";
	cin >> guess;

	return guess;
}

char GetRandomLetter()
{
	return 'a' + (rand() % 26);
}

void AISpeak(string text)
{
	cout << "	AI: " << text << endl;
}

void AISpeakLetters(char letter)
{
	string text = "Here we go! ...";

	for (int i = 0; i < 26; i++)
	{
		char currentLetter = 'a' + i;
		if (letter == currentLetter)
		{
			text += 'A' + i;
		}
		else
		{
			text += 'a' + i;
		}
	}

	text += "...";

	AISpeak(text);
}