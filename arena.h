#ifndef ARENA_H
#define ARENA_H

#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <elements.h>

class Arena : public Element {
public:
    Player *player;
    Bomb *bomb;
    Bot *bot;
    KeyAndDoor *key;
    std::ifstream map;
    int i;
    void drawArena (RenderWindow &window);
    Arena (Texture &texture) : Element(texture){
        TileMap = new std::string[18];
        bot = new Bot(texture,this->TileMap);
        bomb = new Bomb(texture, bot, this->TileMap);
        key = new KeyAndDoor(TileMap);
        map.open("arena.txt");
        i = 0;
        if(map.is_open()) {
            while(map) {
                std::getline(map, TileMap[i]);
                i++;
            }
        }
        map.close();
        key->randomSetPosition();
        bot->randomSetPosition();
        player = new Player(texture, bomb, bot, this->TileMap);
    }
    ~Arena() {
        delete player;
        delete bomb;
        delete bot;
        delete[] TileMap;
    }
};

#endif // ARENA_H
