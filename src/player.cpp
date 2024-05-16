#include "player.hpp"

const int v = 5;

Player::Player(int x, int y)
{
    playerState = NOT_BOUGHT;
    pos = Vector2f(x, y);
    if (!texture.loadFromFile(PICS_PATH + "peashooterAnimatedNoBG.png"))
    {
        debug("no loadedFile");
        return;
    }
    rect.top = 10;
    rect.left = 3;
    rect.height = 32;
    rect.width = 32;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(1.7, 1.7);
}

Player::~Player()
{
}

void Player::render(RenderWindow &window)
{
    window.draw(sprite);
    // for (auto p : projectiles)
    // {
    // p->render(window);
    // }
}

void Player::update(Vector2i pos)
{
    Time elapsed = clock.getElapsedTime();
    if (elapsed.asMilliseconds() >= 100)
    {
        clock.restart();
        current_rect_pos = (current_rect_pos + 1) % 4;
        rect.left = poses_left[current_rect_pos];
        rect.top = poses_top[current_rect_pos];
        sprite.setTextureRect(rect);
    }
    if (is_tagged)
    {
        Vector2f target(static_cast<float>(pos.x) - sprite.getTextureRect().width * 1.7 / 2, static_cast<float>(pos.y) - sprite.getTextureRect().height * 1.7 / 2);
        sprite.setPosition(target);
    }
    fix_position();
    // pos = {sprite.getPosition().x + sprite.getTextureRect().width * 0.05,
    //        sprite.getPosition().y + 10};
    // if (internalClock == 0)
    // {
    //     projectiles.push_back(new Projectile(pos.x, pos.y));
    // }
    // internalClock = (internalClock + 1) % 80;
    // for (auto p : projectiles)
    // {
    //     p->update();
    // }
}

void Player::handle_mouse_release(Vector2i pos)
{
    is_tagged = false;
    planted = true;
}

void Player::handle_mouse_press(Vector2i pos)
{
    if (!planted)
    {
        Vector2f spritePos = sprite.getPosition();
        Vector2f spriteSize = {sprite.getTextureRect().width * 1.7, sprite.getTextureRect().height * 1.7};
        if (pos.x >= spritePos.x && pos.x < spritePos.x + spriteSize.x &&
            pos.y >= spritePos.y && pos.y < spritePos.y + spriteSize.y)
        {
            is_tagged = true;
        }
    }
}

Vector2f Player::get_projectile_pos()
{
    return Vector2f(sprite.getPosition().x + sprite.getTextureRect().width * 1.7, sprite.getPosition().y + 10);
}

void Player::fix_position()
{
    FloatRect rect = sprite.getGlobalBounds();
    rect.top = max(0.f, rect.top);
    rect.top = min(rect.top, HEIGHT - rect.height);
    rect.left = max(0.f, rect.left);
    rect.left = min(rect.left, WIDTH - rect.width);
    sprite.setPosition(rect.left, rect.top);
}

bool Player::is_planted()
{
    return planted;
}