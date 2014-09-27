
#include "mainwindow.h"
#include <QApplication>

#include <time.h>
#include <SFML/Graphics.hpp>
#include <arena.h>
#include <elements.h>


#include <fstream>


using namespace sf;
int main()
{
    Clock clock;
    float time;
    RenderWindow window(VideoMode(Width,Heigth), "BOMBERMAN");

    Texture texture;
    texture.loadFromFile("sprite.png");

    Arena* arena=new Arena(texture);
    while (window.isOpen()) {
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event:: Closed) {
                window.close();
            }
        }

        arena->player->action(time);
        window.clear();
        arena->drawArena(window);
        arena->bomb->action(window,arena->player->rect,arena->player->status, time);
        arena->bot->action(window,time);
        window.draw(arena->player->sprite);
        window.display();
    }
    return 0;
}
