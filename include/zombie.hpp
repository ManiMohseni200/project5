#pragma once

#include "global.hpp"

class Zombie
{
public:
    Zombie(Vector2f p);
    ~Zombie();
    void render(RenderWindow &window);
    void update();
    FloatRect get_rect();
    void get_damaged(int damage);
    bool is_dead();

private:
    int health = 3;
    const int speed = 2;
    Texture texture;
    IntRect rect;
    Sprite sprite;
    Vector2f pos;
};