#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>

#include <SFML/Graphics.hpp>

//#include <elements.cpp>

using namespace std;
using namespace sf;


class Element {
public:
    float currentFrame;
    Sprite sprite;
    std::string *TileMap;
    //interface
    //virtual void action() = 0;
    //interface
    Element (Texture & texture) {
        TileMap = NULL;
        sprite.setTexture(texture);
        currentFrame = 0;
    }
    Element (Texture & texture, std::string *Map) {
        TileMap = Map;
        sprite.setTexture(texture);
        currentFrame = 0;
    }
};

class KeyAndDoor {
public:
    std::string *TileMap;
    int iKey;
    int jKey;
    int iDoor;
    int jDoor;
    void randomSetPosition();
    KeyAndDoor(std::string *Map) {
        TileMap = Map;
        iKey = jKey = iDoor = jDoor = 0;
    }
};

class Bot : public Element {
public:
    float dx[numberBot], dy[numberBot];
    float currentFrame[numberBot];
    FloatRect rect[numberBot];
    int i[numberBot];
    int j[numberBot];
    int dir[numberBot];
    bool status[numberBot];
    bool changeDir[numberBot];
    void randomSetPosition();
    void moveLeft(float &time, int k);
    void moveRight(float &time, int k);
    void moveUp(float &time, int k);
    void moveDown(float &time, int k);
    void discretization(float &time, int k);
    void collisionDetection(int k);
    void action(RenderWindow &window, float &time);
    Bot (Texture& texture, std::string *Map) : Element(texture, Map) {
        for (int k = 0; k < numberBot; k++) {
            dx[k] = dy[k] = 0;
            rect[k] = FloatRect(0, 0, 40, 50);
            i[k] = 0;
            j[k] = 0;
            dir[k] = 1;
            currentFrame[k] = 0;
            changeDir[k] = false;
            status[k] = true;
        }
    }
};

class Bomb : public Element {
public:
    int i;
    int j;
    bool status;
    FloatRect rect;
    Bot *bot;
    void action(RenderWindow &window, FloatRect &rectPlayer, bool &statusPlayer, float &time);
    void setBomb (int i, int j);
    void destructionByExplosion (RenderWindow &window, FloatRect &rectPlayer, bool &statusPlayer);
    void changeStatus(FloatRect &rectPlayer);
    Bomb (Texture & texture, Bot *b,  std::string *Map) : Element(texture, Map) {
        i = 0;
        j = 0;
        status = false;
        rect = FloatRect(0,0,0,0);
        bot = b;
    }
};

class Player : public Element {
public:
    float dx, dy; // скорость движения игрока
    FloatRect rect;
    bool status;
    Bomb *bomb;
    Bot *bot;
    void moveLeft(float &time);
    void moveRight(float &time);
    void moveUp(float &time);
    void moveDown(float &time);
    void discretization(float &time);
    void collisionDetection();
    void botCollisionDetection();
    void action(float &time); // отслеживает нажатие клавиш и отрисовывает игрока с анимацией движения
    Player (Texture &texture, Bomb *b, Bot * bt, std::string *Map) : Element(texture, Map) {
        dx = dy = 0;
        bomb = b;
        bot = bt;
        status = true;
        rect = FloatRect(110, 495, 40, 50);
        sprite.setTextureRect(IntRect(500,0,40,50));
        sprite.setPosition(110, 495);
    }
};

//#include <elements.cpp>
#endif // ELEMENTS_H
