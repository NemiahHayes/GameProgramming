#include "Entity.h"

Entity::Entity()
	: m_bVisible(true)
{

}

Entity::~Entity()
{

}

bool Entity::IsVisible() const
{
	return m_bVisible;
}