#include <iostream>
#include "Enemy.h"
#include "Zombie.h"
#include "Boss.h"

int main()
{
	std::cout << "STARTING PROGRAM" << std::endl;
	
	const int y = 8;
	constexpr int x = y;

	Enemy* basicContainer[x]{};

	for (int i = 0; i < 4; i++)
	{
		basicContainer[i] = new Enemy();
	}

	for (int i = 4; i < 5; i++)
	{
		basicContainer[i] = new Boss();
	}

	for (int i = 5; i < x; i++)
	{
		basicContainer[i] = new Zombie();
	}

	//Make Noise
	for (int i = 0; i < x; i++)
	{
		basicContainer[i]->MakeNoise();
	}

	//Draw
	for (int i = 0; i < x; i++)
	{
		basicContainer[i]->Draw();
	}

	bool p = true;
	while (p)
	{
		for (int i = 0; i < x; i++)
		{
			basicContainer[i]->Move();
			basicContainer[i]->Draw();
		}

		char input;
		std::cin >> input;
		if (input == 'q')
		{
			p = false;
		}
	}

	//Delete Pointer
	for (int i = 0; i < 8; i++)
	{
		delete basicContainer[i];
		basicContainer[i] = 0;
	}

	std::cout << "Enemy Size: " << sizeof(Enemy) << std::endl;
	std::cout << "Zombie Size: " << sizeof(Zombie) << std::endl;
	std::cout << "Boss Size: " << sizeof(Boss) << std::endl;
	return 0;
}