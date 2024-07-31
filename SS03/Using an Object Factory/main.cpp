#include <iostream>
#include "Entity.h"
#include "Zombie.h"
#include "HealthPack.h"
#include "AmmoPack.h"

enum EntityType
{
	ZOMBIE, HEALTHPACK, AMMOPACK
};

Entity* CreateEntity(EntityType entityType);

int main()
{
	Entity* zombie = CreateEntity(ZOMBIE);
	Entity* healthpack = CreateEntity(HEALTHPACK);
	Entity* ammopack = CreateEntity(AMMOPACK);

	std::cout << "Zombie: " << zombie->IsVisible() << std::endl;
	std::cout << "Health: " << healthpack->IsVisible() << std::endl;
	std::cout << "Ammo: " << ammopack->IsVisible() << std::endl;
	delete zombie;
	delete healthpack;
	delete ammopack;
	zombie = 0;
	healthpack = 0;
	ammopack = 0;

	return 0;
}

Entity* CreateEntity(EntityType entityType)
{
	switch (entityType)
	{
	case ZOMBIE:
		return new Zombie();
		break;
	case HEALTHPACK:
		return new HealthPack();
		break;
	case AMMOPACK:
		return new AmmoPack();
		break;
	}
}