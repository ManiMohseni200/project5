#include "handler.hpp"

Handler::Handler(Player *p)
{
    player = p;
}

Handler::~Handler()
{
    for (auto p : projectiles)
    {
        delete p;
    }
}

void Handler::update()
{
    handle_collision();
    Time elapsed = clock.getElapsedTime();
    if (elapsed.asMilliseconds() >= 700 && player->is_planted())
    {
        clock.restart();
        add_projectile();
        // add_zombie();
    }
    Time zelapsed = zombie_clock.getElapsedTime();
    if (zelapsed.asMilliseconds() >= 1400)
    {
        zombie_clock.restart();
        add_zombie();
    }
    for (auto p : projectiles)
    {
        p->update();
    }
    for (auto z : zombies)
    {
        z->update();
    }
    delete_out_of_bonds();
}

void Handler::render(RenderWindow &window)
{
    for (auto p : projectiles)
    {
        p->render(window);
    }
    for (auto z : zombies)
    {
        z->render(window);
    }
}

void Handler::add_projectile()
{
    Projectile *p = new Projectile(player->get_projectile_pos());
    projectiles.push_back(p);
}

void Handler::add_zombie()
{
    Zombie *z = new Zombie(Vector2f(WIDTH, rand() % (HEIGHT - 60)));
    zombies.push_back(z);
}

void Handler::delete_out_of_bonds()
{
    vector<Projectile *> trash;
    for (auto p : projectiles)
    {
        if (p->is_out())
        {
            trash.push_back(p);
        }
    }
    projectiles.erase(remove_if(projectiles.begin(), projectiles.end(), [](auto p)
                                { return p->is_out(); }),
                      projectiles.end());
    for (auto p : trash)
    {
        delete p;
    }
}

void Handler::handle_collision()
{

    vector<Projectile *> trash_p;
    vector<Zombie *> trash_z;
    for (auto p : projectiles)
    {
        for (auto z : zombies)
        {
            FloatRect p_rect = p->get_rect();
            FloatRect z_rect = z->get_rect();
            if (z_rect.intersects(p_rect))
            {
                z->get_damaged(p->get_damage());
                if (z->is_dead())
                {
                    trash_z.push_back(z);
                }
                trash_p.push_back(p);
            }
        }
    }

    for (auto p : trash_p)
    {
        projectiles.erase(remove(projectiles.begin(), projectiles.end(), p), projectiles.end());
        delete p;
    }
    for (auto z : trash_z)
    {
        zombies.erase(remove(zombies.begin(), zombies.end(), z), zombies.end());
        delete z;
    }
}