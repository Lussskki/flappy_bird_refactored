#include "Window.h"
#include <iostream>

#include <filesystem>
namespace fs = std::filesystem;

Window::Window() {
    std::cout << "Current path: " << fs::current_path() << std::endl;

    window.create(sf::VideoMode(400, 600), "Flappy Bird Refactored");
    window.setFramerateLimit(60);

    fs::path basePath = fs::current_path() / "assets" / "bird";

    if (!bird.textureUp.loadFromFile((basePath / "bluebird-upflap.png").string()) ||
        !bird.textureMid.loadFromFile((basePath / "bluebird-midflap.png").string()) ||
        !bird.textureDown.loadFromFile((basePath / "bluebird-downflap.png").string()))
    {
        std::cerr << "Failed to load bird textures\n";
    }

    bird.frames = { &bird.textureMid, &bird.textureDown, &bird.textureUp };
    bird.currentFrame = 0;
    bird.animTimer = 0;
    bird.animInterval = 0.15f;

    bird.sprite.setTexture(*bird.frames[0]);
    bird.sprite.setScale(30.f / bird.frames[0]->getSize().x, 30.f / bird.frames[0]->getSize().y);
    bird.sprite.setPosition(100.f, 300.f);
}




//Window::Window()
//{
//    window.create(sf::VideoMode(400, 600), "Flappy Bird Refactored");
//    window.setFramerateLimit(60);
//
//    // Setup bird
//    bird.texture.loadFromFile(".\\assets\\bird\\bluebird-midflap.png");
//    //if (!bird.texture.loadFromFile("assets/bird/bluebird-midflap.png")) 
//    //{
//    //    std::cout << "Failed to load bird texture from assets/bird/bluebird-midflap.png\n";
//    //}
//
//    bird.sprite.setTexture(bird.texture);
//    bird.sprite.setPosition(100.f, 300.f);
//    bird.sprite.setScale(2.f, 2.f);
//}

void Window::run()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                bird.flap();
        }

        float dt = clock.restart().asSeconds();
        bird.update(dt);

        window.clear();
        bird.draw(window);
        window.display();
    }
}
