#ifndef PONG_H
#define PONG_H
#include "resource_manager.h"
class Pong
{
    public:

        void processInput();
        void update();
        void render();

    private:
        enum GameState
        {
            GAME_MENU,
            GAME_ACTIVE,
            GAME_P1_WIN,
            GAME_P1_LOSE
        };
        ResourceManager rM;

        void init();
};
#endif
