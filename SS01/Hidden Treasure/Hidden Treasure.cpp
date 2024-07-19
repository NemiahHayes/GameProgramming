/*
    OUTPUT user introduction methd
    REPEAT
            OUTPUT ask for user input
            INPUT character direction
            STORE player input

            IF answer = direction (n,e,s,w), (N,E,S,W)
                OUTPUT new character position
            
            IF answer = q, Q
                OUT user quits
    UNTIL user quits
*/

#include <iostream>

void startupmsg();
void mainloop();
void printpos(int, int);
bool movecharacter(char, int&, int&);

//Msg Functions
void positionmsg(int&, int&);
void piratemsg();
void idolmsg();
void gemstonemsg();
void artworkmsg();
void treasuremsg();

int main()
{
    startupmsg();

    mainloop();
}

//Print Start Message
void startupmsg()
{
    std::cout << "Find the Hidden Treasure!" << '\n' << "----------" << std::endl;
}

//Print Main Loop
void mainloop()
{
    //Base Variables
    bool playing = true;
    int x = 0;
    int y = 0;

    while (playing)
    {
        printpos(x, y);

        bool input = false;
        while (!input)
        {
            //Get Input
            char move = '\0';
            std::cin >> move;
            
            //Check if Quitting
            if (move != 'q' && move != 'Q')
            {
                input = movecharacter(move, x, y);
                positionmsg(x,y);
            }
            else
            {
                playing = false;
            }
        }
    }
}

//Print Player Position
void printpos(int x, int y)
{
    std::cout << "You are at (" << x << ", " << y << "). Move (N/E/S/W)?";
}

//Print Message if at Edge of World
void printendmsg()
{
    std::cout << "+-----------------------------------------+" << '\n' <<
        "| You have reached the edge of the world!|" << '\n' <<
        "+ ---------------------------------------- - +" << std::endl;
}

//Player Position Messages
void positionmsg(int& x, int& y)
{
    //Edge of World
    if (x == 10 || y == 10 || x == -10 || y == -10)
    {
        printendmsg();
    }

    //Pirate's Chest
    if (x == 2 && y == 3)
    {
        piratemsg();
    }

    //Golden Idol
    if (x == -5 && y == -3)
    {
        idolmsg();
    }

    //Precious Gemstones
    if (x == 1 && y == -2)
    {
        gemstonemsg();
    }

    //Lost artwork
    if (x == 5 && y == 2)
    {
        artworkmsg();
    }

    //Fifth Treasure
    if (x == 4 && y == 4)
    {
        treasuremsg();
    }
}

//Player Position Messages 
void piratemsg()
{
    std::cout << "*******************************" << '\n' <<
        " * You found a pirate's chest! * " << '\n' <<
        "*****************************" << std::endl;
}

void idolmsg()
{
    std::cout << "*******************************" << '\n' <<
        " * You found a pirate's chest! * " << '\n' <<
        "******************************" << std::endl;
}

void gemstonemsg()
{
    std::cout << "*******************************" << '\n' <<
        " * You found precious gemstones! * " << '\n' <<
        "******************************" << std::endl;
}

void artworkmsg()
{
    std::cout << "*******************************" << '\n' <<
        " * You found a lost artwork! * " << '\n' <<
        "******************************" << std::endl;
}

void treasuremsg()
{
    std::cout << "*******************************" << '\n' <<
        " * You found a treasure map! * " << '\n' <<
        "******************************" << std::endl;
}

//Player Input
bool movecharacter(char input, int& x, int& y)
{
    if (input == 'n' || input == 'N') //North Move
    {
        if (y < 10)
        {
            y++;
        }

        return true;
    }
    else if (input == 'e' || input == 'E') //East Move
    {
        if (x < 10)
        {
            x++;
        }

        return true;
    }
    else if (input == 's' || input == 'S') //South Move
    {
        if (y > -10)
        {
            y--;
        }

        return true;
    }
    else if (input == 'w' || input == 'W') //West Move
    {
        if (x > -10)
        {
            x--;
        }

        return true;
    }

    return false;
}