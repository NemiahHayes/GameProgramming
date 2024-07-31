#include "Enemy.h"
#include <iostream>

#define DEBUG 1
#undef DEBUG

Enemy::Enemy() :
	m_x(0), m_y(0)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> xrandom(0, 120);
	std::uniform_int_distribution<> yrandom(0, 30);

	m_x = xrandom(gen);
	m_y = yrandom(gen);

	console_window = GetStdHandle(STD_OUTPUT_HANDLE);

#ifdef DEBUG
	std::cout << "Constructor called on object at: " << this << " (Enemy)." << std::endl;
#endif
}

Enemy::~Enemy()
{
#ifdef DEBUG
	std::cout << "Destructor called on object at: " << this << " (Enemy)." << std::endl;
#endif
}

void
Enemy::MakeNoise() const
{
	std::cout << "Enemy" << this << "makes generic noise." << std::endl;
}

void
Enemy::Draw() const
{
	MoveToCursor(m_x, m_y);

	TextColor(0, 4);

	std::cout << "E";

	TextColor(15, 0);

	std::cout << std::endl;
}

void Enemy::TextColor(int foreground, int background) const
{
	int colour = ((background & 0x0F) << 4) | (foreground &0x0F); 
	SetConsoleTextAttribute(console_window, colour);
}

void Enemy::MoveToCursor(int x, int y) const
{
	COORD position;
	position.X = x;
	position.Y = y;

	SetConsoleCursorPosition(console_window, position);
}

void Enemy::Move()
{
	MoveToCursor(m_x, m_y);
	TextColor(15, 0);
	std::cout << " ";

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> dirrandom(0, 3);

	int newdir = dirrandom(gen);

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