#include "Boss.h"
#include "Enemy.h"
#include <iostream>

#define DEBUG 1
#undef DEBUG

Boss::Boss() {
#ifdef DEBUG
	std::cout << "Constructor called on object at: " << this << " (Boss)." << std::endl;
#endif
}

Boss::~Boss()
{
#ifdef DEBUG
	std::cout << "Destructor called on object at: " << this << " (Boss)." << std::endl;
#endif
}

void
Boss::MakeNoise() const
{
	std::cout << "Boss [" << this << "] makes GRRAAAAUUUU noise." << std::endl;
}

void
Boss::Draw() const
{
	COORD position;

	TextColor(0, 14);

	MoveToCursor(m_x, m_y + 1);
	std::cout << "+-+";

	MoveToCursor(m_x, m_y);
	std::cout << "|B|";

	MoveToCursor(m_x, m_y - 1);
	std::cout << "+-+";

	TextColor(15, 0);

	std::cout << std::endl;
}

void Boss::Move()
{
	MoveToCursor(m_x, m_y + 1);
	TextColor(15, 0);
	std::cout << "   ";
	MoveToCursor(m_x, m_y);
	TextColor(15, 0);
	std::cout << "   ";
	MoveToCursor(m_x, m_y - 1);
	TextColor(15, 0);
	std::cout << "   ";

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> xrandom(0, 120);
	std::uniform_int_distribution<> yrandom(0, 30);

	m_x = xrandom(gen);
	m_y = yrandom(gen);
}