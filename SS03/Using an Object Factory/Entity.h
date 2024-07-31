#pragma once
#ifndef __ENTITY_H
#define __ENTITY_H

class Entity {
public:
	Entity();
	virtual
	~Entity();
	bool IsVisible() const;
	
private:
	bool m_bVisible;
};

#endif //__ENTITY_H
