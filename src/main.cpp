#include "Game.h"

int main()
{
    Game game;

    if (game.Init())
    {
        game.RunLoop();
    }

    game.Shutdown();

    return 0;
}