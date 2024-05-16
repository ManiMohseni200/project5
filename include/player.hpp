#pragma once

#include "global.hpp"
#include "projectile.hpp"

enum PlayerState
{
    NOT_BOUGHT,
    BENG_DRAGGED,
    PLANTED_IDLE,
    PLANTED_ZOMBIE_IN_LINE
};

class Player
{
public:
    Player(int x, int y);
    ~Player();
    void render(RenderWindow &window);
    void update(Vector2i pos);
    void handle_mouse_press(Vector2i pos);
    void handle_mouse_release(Vector2i pos);
    Vector2f get_projectile_pos();
    void fix_position();
    bool is_planted();

private:
    PlayerState playerState;
    Clock clock;
    int poses_top[8] = {11, 10, 10, 10, 10, 10, 10, 10};
    int poses_left[8] = {3, 36, 69, 102, 134, 167, 200, 233};
    int current_rect_pos = 0;
    Texture texture;
    Sprite sprite;
    IntRect rect;
    Vector2f pos;
    bool is_tagged = false;
    int internalClock = 0;
    bool planted = false;
};