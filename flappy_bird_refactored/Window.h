#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include "Bird.h"

class Window
{
public:
    Window();              
    void run();            

private:
    sf::RenderWindow window;
    Bird bird;             
};

#endif
