#include <iostream>
#include <cstdlib>

void RollTwoDice(int d1, int d2);

int main()
{
    srand((int)time(0));

    int d1 = 0;
    int d2 = 0;
    
    d1 = (rand() % 6) + 1;
    d2 = (rand() % 6) + 1;

    RollTwoDice(d1, d2);
}

void RollTwoDice(int d1, int d2)
{
    std::cout << "Dice 1: ";
    std::cout << d1 <<
    std::endl;

    std::cout << "Dice 2: ";
    std::cout << d2;
    std::cout << " " <<
    std::endl;
}