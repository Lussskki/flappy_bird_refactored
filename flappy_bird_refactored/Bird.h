#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>

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
	sf::Texture texture;
	float velocity;
	float gravity;
};

#endif