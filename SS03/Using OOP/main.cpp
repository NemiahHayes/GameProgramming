//Difference Between Local Stack and Free Store Objects
//

#include <iostream>
#include <crtdbg.h>
#include "Player.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |_CRTDBG_LEAK_CHECK_DF);
    Player testPlayer = Player();
    
    //Set Methods
    testPlayer.SetHealth(250);
    testPlayer.SetExperience(1000);
    testPlayer.SetPowerup(100);

    //Get Methods
    std::cout << "Health: " << testPlayer.GetHealth() << std::endl;
    std::cout << "Experience: " << testPlayer.GetExperience() << std::endl;
    std::cout << "Powerup: " << testPlayer.GetPowerup() << std::endl;

    //Print Stats
    testPlayer.PrintStats();

    //Pointer
    Player* pPlayer = NULL;
    Player* pPlayerNew = new Player();
    pPlayer = pPlayerNew;
    pPlayer->SetHealth(10);
    pPlayer->SetExperience(10001);
    pPlayer->SetPowerup(50);
    pPlayer->PrintStats();
    delete pPlayerNew;
    pPlayerNew = 0;

    return 0;
}