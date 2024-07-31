#include "Player.h"
#include <iostream>

Player::Player()
: health(100),
experience(0),
powerup(0)
{
	std::cout << "A Player object was created!" << '\n';
}

Player::~Player()
{
	std::cout << "A Player object was destroyed!"  << '\n';
}

void
Player::PrintStats()
{
	std::cout << "Health: " << GetHealth() << '\n'
		<< "Experience Level: " << GetExperience() << '\n'
		<< "Power-up Level: " << GetHealth() << '\n';
}

float
Player::GetHealth() const
{
	return health;
}

float
Player::GetExperience() const
{
	return experience;
}

float
Player::GetPowerup() const
{
	return powerup;
}

void
Player::SetHealth(float c_health)
{
	health = c_health;
}

void
Player::SetExperience(float c_experience)
{
	experience = c_experience;
}

void
Player::SetPowerup(float c_powerup)
{
	powerup = c_powerup;
}