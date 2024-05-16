#include "zombie.hpp"

Zombie::Zombie(Vector2f p)
{
    pos = p;
    if (!texture.loadFromFile(PICS_PATH + "Zombie_healthy.png"))
    {
        return;
    }
    sprite.setTexture(texture);
    rect.width = 291;
    rect.height = 465;
    sprite.setScale(0.2, 0.2);
    sprite.setTextureRect(rect);
}

Zombie::~Zombie()
{
}

void Zombie::render(RenderWindow &window)
{
    window.draw(sprite);
}

void Zombie::update()
{
    pos.x -= speed;
    sprite.setPosition(pos);
}

FloatRect Zombie::get_rect()
{
    return sprite.getGlobalBounds();
}

void Zombie::get_damaged(int damage)
{
    health -= damage;
}

bool Zombie::is_dead()
{
    return health == 0;
}