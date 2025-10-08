#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include <vector>

class Bird
{
public:
    Bird();

    void update(float dt);
    void jump();
    void draw(sf::RenderWindow& window);
    void flap();

public:
    sf::Sprite sprite;

    // Store multiple textures for animation
    sf::Texture textureUp;
    sf::Texture textureMid;
    sf::Texture textureDown;
    std::vector<sf::Texture*> frames;

    int currentFrame;
    float animTimer;
    float animInterval;

    float velocity;
    float gravity;
};

#endif
