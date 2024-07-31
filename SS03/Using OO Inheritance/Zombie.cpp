#include "Zombie.h"
#include "Enemy.h"
#include <iostream>

#define DEBUG 1
#undef DEBUG

Zombie::Zombie() :
	turns(5), newdir(0)
{
#ifdef DEBUG
	std::cout << "Constructor called on object at: " << this << " (Zombie)." << std::endl;
#endif
}

Zombie::~Zombie()
{
#ifdef DEBUG
	std::cout << "Destructor called on object at: " << this << " (Zombie)." << std::endl;
#endif DEBUG
}

void
Zombie::MakeNoise() const
{
	std::cout << "Zombie [" << this << "] makes OHHH, AHHHHHYAAAA noise." << std::endl;
}

void Zombie::Draw() const
{
	MoveToCursor(m_x, m_y);

	TextColor(0, 1);
	//0 - Black, 4 - Red

	std::cout << "Z";

	TextColor(15, 0);

	std::cout << std::endl;
}

void Zombie::Move()
{
	MoveToCursor(m_x, m_y);
	TextColor(15, 0);
	std::cout << " ";

	if (turns >= 5)
	{
		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_int_distribution<> dirrandom(0, 3);

		newdir = dirrandom(gen);
	}

	switch (newdir) {
	case 0:
		m_x++;
		break;
	case 1:
		m_x--;
		break;
	case 2:
		m_y++;
		break;
	case 3:
		m_y--;
		break;
	}
}