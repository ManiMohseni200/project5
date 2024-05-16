#include "projectile.hpp"

Projectile::Projectile(Vector2f p)
{
    pos = p;
    if (!texture.loadFromFile(PICS_PATH + "pea.png"))
    {
        return;
    }
    rect.height = 138;
    rect.width = 138;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(0.2, 0.2);
}

Projectile::~Projectile()
{
}

void Projectile::render(RenderWindow &window)
{
    window.draw(sprite);
}

void Projectile::update()
{
    pos.x += speed;
    sprite.setPosition(pos);
}

bool Projectile::is_out()
{
    return sprite.getPosition().x >= 1400;
}

FloatRect Projectile::get_rect()
{
    return sprite.getGlobalBounds();
}

int Projectile::get_damage()
{
    return damage;
}