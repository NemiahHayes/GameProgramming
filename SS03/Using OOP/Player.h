#pragma once
#ifndef __Player_H
#define __Player_H

class Player {
private: 
	float health;
	float experience;
	float powerup;

public:
	Player();
	~Player();

	void SetHealth(float);
	void SetExperience(float);
	void SetPowerup(float);
	float GetHealth() const;
	float GetExperience() const;
	float GetPowerup() const;
	void PrintStats();
};

#endif // __Player_H
