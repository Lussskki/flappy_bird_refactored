#include "Bird.h"

Bird::Bird() 
{
    velocity = 0.f;
    gravity = 900.f;
    
}

void Bird::flap()
{
    velocity = -350.f;
}

void Bird::jump()
{

}

void Bird::update(float dt) 
{
    velocity += gravity * dt;
    sprite.move(0, velocity * dt);
}

void Bird::draw(sf::RenderWindow& window) 
{
    window.draw(sprite);
}
