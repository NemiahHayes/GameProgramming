#include "Zombie.h"
#include <iostream>

Zombie::Zombie(){

}

Zombie::~Zombie()
{
	std::cout << "A Player object was destroyed!" << '\n';
}