#pragma once

#include "global.hpp"
#include "player.hpp"
#include "projectile.hpp"
#include "zombie.hpp"

class Handler
{
public:
    Handler(Player *p);
    ~Handler();
    void update();
    void render(RenderWindow &window);

private:
    Clock clock;
    Clock zombie_clock;
    Player *player;
    vector<Projectile *> projectiles;
    vector<Zombie *> zombies;
    void add_projectile();
    void delete_out_of_bonds();
    void add_zombie();
    void handle_collision();
};