#pragma once
#ifndef __BOSS_H
#define __BOSS_H

#include "Enemy.h"

class Boss :
	public Enemy
{
public:
	Boss();
	virtual ~Boss() override;

	virtual void MakeNoise() const override;
	virtual void Draw() const override;
	virtual void Move() override;
};

#endif //__BOSS_H