#pragma once
#ifndef __ZOMBIE_H
#define __ZOMBIE_H

#include "Enemy.h"

class Zombie :
	public Enemy
{
public:
	Zombie();
	virtual ~Zombie() override;

	virtual void MakeNoise() const override;
	virtual void Draw() const override;
	virtual void Move() override;
private:
	int turns;
	int newdir;
};

#endif //__ZOMBIE_H