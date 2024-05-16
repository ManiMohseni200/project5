#include "global.hpp"
#include "system.hpp"
#include "player.hpp"

int main()
{

    System mySystem(WIDTH, HEIGHT);
    mySystem.run();

    return 0;
}