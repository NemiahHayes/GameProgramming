#pragma once
#ifndef __ENEMY_H
#define __ENEMY_H

#include <Windows.h>
#include <random>

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void MakeNoise() const;
	virtual void Draw() const;
	virtual void Move();

protected:
	int m_x;
	int m_y;
	HANDLE console_window;
	void TextColor(int foreground, int background) const;
	void MoveToCursor(int x, int y) const;

private:
	Enemy(Enemy& enemyCopy);
};

#endif //__ENEMYH