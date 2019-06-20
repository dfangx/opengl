#ifndef PONG_H
#define PONG_H
class Pong
{
    public:
        Pong();

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

        void init();
};
#endif
