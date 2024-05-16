#pragma once

#include "global.hpp"

class Projectile
{
public:
    Projectile(Vector2f p);
    ~Projectile();
    void render(RenderWindow &window);
    void update();
    bool is_out();
    FloatRect get_rect();
    int get_damage();

private:
    int damage = 1;
    Texture texture;
    Sprite sprite;
    IntRect rect;
    Vector2f pos;
    int speed = 10;
};