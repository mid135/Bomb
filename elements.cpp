#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "elements.h"


 void Bomb::setBomb(int i, int j) {
    if (!status) {
        this->i = i;
        this->j = j;
        TileMap[i][j] = 'b';
        status = true;
        rect.left = j * 55 + 7.5;
        rect.top = i * 55 + 2.5;
    }
}

 void Bomb::changeStatus(FloatRect &rectPlayer) {
    if (status) {
        if (TileMap[i][j] != 'A' && (fabs(rect.left - rectPlayer.left) > 50
                                     || fabs(rect.top - rectPlayer.top) > 53)) {
            TileMap[i][j] = 'B';
        }
    }
}

 void Bomb::destructionByExplosion(RenderWindow &window, FloatRect &rectPlayer, bool &statusPlayer) {
    for (int k = this->i; k < this->i+2; k++) {
        if (k < amountHeight) {
            if (TileMap[k][j] == 'P') break;
            if (TileMap[k][j] == 'c') TileMap[k][j] = 'C';
            if (TileMap[k][j] == 'v') TileMap[k][j] = 'V';
            if (TileMap[k][j] == 'K' || TileMap[k][j] == 'D' || TileMap[k][j] == ' ') {
                TileMap[k][j] = ' ';
                sprite.setTextureRect(IntRect(56*int(currentFrame),280,55,55));
                sprite.setPosition(j*55 + 10, k*55);
                window.draw(sprite);
            }
            for (int l = 0; l < numberBot; l++) {
                if (bot->status[l]) {
                    if (fabs(j*55 - bot->rect[l].left) < 27 && fabs(k*55 - bot->rect[l].top) < 27) {
                        bot->status[l] = false;
                        break;
                    }
                }
            }
            if (statusPlayer) {
                if (fabs(j*55 - rectPlayer.left) < 27 && fabs(k*55 - rectPlayer.top) < 27) {
                    statusPlayer = false;
                }
            }
        }
    }
    for (int k = this->i-1; k > this->i-2; k--) {
        if (k >= 0) {
            if (TileMap[k][j] == 'P') break;
            if (TileMap[k][j] == 'c') TileMap[k][j] = 'C';
            if (TileMap[k][j] == 'v') TileMap[k][j] = 'V';
            if (TileMap[k][j] == 'K' || TileMap[k][j] == 'D' || TileMap[k][j] == ' ') {
                TileMap[k][j] = ' ';
                sprite.setTextureRect(IntRect(56*int(currentFrame),280,55,55));
                sprite.setPosition(j*55 + 10, k*55);
                window.draw(sprite);
            }
            for (int l = 0; l < numberBot; l++) {
                if (bot->status[l]) {
                    if (fabs(j*55 - bot->rect[l].left) < 27 && fabs(k*55 - bot->rect[l].top) < 27) {
                        bot->status[l] = false;
                        break;
                    }
                }
            }
            if (statusPlayer) {
                if (fabs(j*55 - rectPlayer.left) < 27 && fabs(k*55 - rectPlayer.top) < 27) {
                    statusPlayer = false;
                }
            }
        }
    }
    for (int j = this->j; j < this->j+2; j++) {
        if (j < amountWidth) {
            if (TileMap[i][j] == 'P') break;
            if (TileMap[i][j] == 'c') TileMap[i][j] = 'C';
            if (TileMap[i][j] == 'v') TileMap[i][j] = 'V';
            if (TileMap[i][j] == 'K' || TileMap[i][j] == 'D' || TileMap[i][j] == ' ') {
                TileMap[i][j] = ' ';
                sprite.setTextureRect(IntRect(56*int(currentFrame),280,55,55));
                sprite.setPosition(j*55 + 10, i*55);
                window.draw(sprite);
            }
            for (int l = 0; l < numberBot; l++) {
                if (bot->status[l]) {
                    if (fabs(j*55 - bot->rect[l].left) < 27 && fabs(i*55 - bot->rect[l].top) < 27) {
                        bot->status[l] = false;
                        break;
                    }
                }
            }
            if (statusPlayer) {
                if (fabs(j*55 - rectPlayer.left) < 27 && fabs(i*55 - rectPlayer.top) < 27) {
                    statusPlayer = false;
                }
            }
        }
    }
    for (int j = this->j-1; j > this->j-2; j--) {
        if (j >= 0) {
            if (TileMap[i][j] == 'P') break;
            if (TileMap[i][j] == 'c') TileMap[i][j] = 'C';
            if (TileMap[i][j] == 'v') TileMap[i][j] = 'V';
            if (TileMap[i][j] == 'K' || TileMap[i][j] == 'D' || TileMap[i][j] == ' ') {
                TileMap[i][j] = ' ';
                sprite.setTextureRect(IntRect(56*int(currentFrame),280,55,55));
                sprite.setPosition(j*55 + 10, i*55);
                window.draw(sprite);
            }
            for (int l = 0; l < numberBot; l++) {
                if (bot->status[l]) {
                    if (fabs(j*55 - bot->rect[l].left) < 27 && fabs(i*55 - bot->rect[l].top) < 27) {
                        bot->status[l] = false;
                        break;
                    }
                }
            }
            if (statusPlayer) {
                if (fabs(j*55 - rectPlayer.left) < 27 && fabs(i*55 - rectPlayer.top) < 27) {
                    statusPlayer = false;
                }
            }
        }
    }
}

 void Bomb::action(RenderWindow &window, FloatRect &rectPlayer, bool &statusPlayer,  float &time) {
    if (TileMap[i][j] == 'b' || TileMap[i][j] == 'B') {
        currentFrame += 0.001*time;
        if (currentFrame > 7) {
            currentFrame = 0;
            TileMap[i][j] = 'A';
        }
        sprite.setTextureRect(IntRect(56*int(currentFrame),58,55,55));
        sprite.setPosition(j*55 + 10, i*55);
        window.draw(sprite);
    }
    if (TileMap[i][j] == 'A' && status) {
        currentFrame += 0.01*time;
        if (currentFrame > 3) {
            currentFrame = 0;
            TileMap[i][j] = ' ';
            status = false;
        }
        sprite.setTextureRect(IntRect(56*int(currentFrame),280,55,55));
        sprite.setPosition(j*55 + 10, i*55);
        window.draw(sprite);
        destructionByExplosion(window,rectPlayer, statusPlayer);
    }
}




 void Bot::collisionDetection(int k) {
    for (int i = rect[k].top/55; i < (rect[k].top + rect[k].height)/55; i++) {
        for (int j = rect[k].left/55; j < (rect[k].left + rect[k].width)/55; j++) {
            if (i < amountHeight && j < amountWidth) {
                if(TileMap[i][j] == 'P' || TileMap[i][j] == 'K' || TileMap[i][j] == 'B'
                        || TileMap[i][j] == 'c' || TileMap[i][j] == 'v') {
                    if (dx[k] > 0) {
                        rect[k].left = j * 55 - rect[k].width;
                        dir[k] = rand()%4;
                        dx[k] = 0;
                    }
                    if (dx[k] < 0) {
                        rect[k].left = j * 55 + 55;
                        dir[k] = rand()%4;
                        dx[k] = 0;
                    }
                    if (dy[k] > 0) {
                        rect[k].top = i * 55 - rect[k].height;
                        dir[k] = rand()%4;
                        dy[k] = 0;
                    }
                    if (dy[k] < 0) {
                        rect[k].top = i * 55 + 55;
                        dir[k] = rand()%4;
                        dy[k] = 0;
                    }
                }
            }

        }
    }
}

 void Bot::discretization(float &time, int k) {
    if (dx[k] < 0) {
        if (fabs( fabs(rect[k].left - (int(rect[k].left/55))*55) - 7.5 ) < 2 ) {
            dx[k] = 0;
            rect[k].left = int(rect[k].left/55)*55 + 7.5;
            sprite.setPosition(rect[k].left, rect[k].top);
            sprite.setTextureRect(IntRect(0,225,55,55));
            changeDir[k] = false;
        } else {
            moveLeft(time, k);
        }
    } else {
        if (dx[k] > 0) {
            if (fabs( fabs(rect[k].left - (int(rect[k].left/55))*55) - 7.5 ) < 2 ) {
                dx[k] = 0;
                rect[k].left = int(rect[k].left/55)*55 + 7.5;
                sprite.setPosition(rect[k].left, rect[k].top);
                sprite.setTextureRect(IntRect(0,225,55,55));
                changeDir[k] = false;
            } else {
                moveRight(time, k);
            }
        } else {
            if (dy[k] < 0) {
                if (fabs( fabs(rect[k].top - (int(rect[k].top/55))*55) - 2.5 ) < 2 ) {
                    dy[k] = 0;
                    rect[k].top = int(rect[k].top/55)*55 + 2.5;
                    sprite.setPosition(rect[k].left, rect[k].top);
                    sprite.setTextureRect(IntRect(0,225,55,55));
                    changeDir[k] = false;
                } else {
                    moveUp(time, k);
                }
            } else {
                if (dy[k] > 0) {
                    if (fabs( fabs(rect[k].top - (int(rect[k].top/55))*55) - 7.5 ) < 2 ) {
                        dy[k] = 0;
                        rect[k].top = int(rect[k].top/55)*55 + 2.5;
                        sprite.setPosition(rect[k].left, rect[k].top);
                        sprite.setTextureRect(IntRect(0,225,55,55));
                        changeDir[k] = false;
                    } else {
                        moveDown(time, k);
                    }
                } else changeDir[k] = 0;
            }
        }
    }
}

 void Bot::moveLeft(float &time, int k) {
    dx[k] = -0.1;
    dy[k] = 0;
    rect[k].left += dx[k]*time;
    if (rect[k].left < 0) {
        rect[k].left = 0;
        dx[k] = 0;
        dir[k] = rand()%4;
    }
    currentFrame[k] += 0.005*time;
    if (rand()%201 == 200) {
        dir[k] = rand()%4;
        changeDir[k] = true;
    }
    if (currentFrame[k] > 2) currentFrame[k] -= 2;
    sprite.setTextureRect(IntRect(55*int(currentFrame[k]),225,55,55));
    sprite.setPosition(rect[k].left, rect[k].top);
}

 void Bot::moveRight(float &time, int k) {
    dx[k] = 0.1;
    dy[k] = 0;
    rect[k].left += dx[k]*time;
    if (rect[k].left > Width - 40) {
        rect[k].left = Width - 40;
        dx[k] = 0;
        dir[k] = rand()%4;
    }
    currentFrame[k] += 0.005*time;
    if (rand()%201 == 200) {
        dir[k] = rand()%4;
        changeDir[k] = true;
    }
    if (currentFrame[k] > 2) currentFrame[k] -= 2;
    sprite.setTextureRect(IntRect(55*int(currentFrame[k]),225,55,55));
    sprite.setPosition(rect[k].left, rect[k].top);
}

 void Bot::moveUp(float &time, int k) {
    dy[k] = -0.1;
    dx[k] = 0;
    rect[k].top += dy[k]*time;
    if (rect[k].top < 0) {
        rect[k].top = 0;
        dy[k] = 0;
        dir[k] = rand()%4;
    }
    currentFrame[k] += 0.005*time;
    if (rand()%201 == 200) {
        dir[k] = rand()%4;
        changeDir[k] = true;
    }
    if (currentFrame[k] > 2) currentFrame[k] -= 2;
    sprite.setTextureRect(IntRect(55*int(currentFrame[k]),225,55,55));
    sprite.setPosition(rect[k].left, rect[k].top);
}

 void Bot::moveDown(float &time, int k) {
    dy[k] = 0.1;
    dx[k] = 0;
    rect[k].top += dy[k]*time;
    if (rect[k].top > Heigth - 50) {
        rect[k].top = Heigth - 50;
        dy[k] = 0;
        dir[k] = rand()%4;
    }
    currentFrame[k] += 0.005*time;
    if (rand()%201 == 200) {
        dir[k] = rand()%4;
        changeDir[k] = true;
    }
    if (currentFrame[k] > 2) currentFrame[k] -= 2;
    sprite.setTextureRect(IntRect(55*int(currentFrame[k]),225,55,55));
    sprite.setPosition(rect[k].left, rect[k].top);
}

 void Bot::action(RenderWindow &window, float &time) {
    int k = 0;
    while (k < numberBot) {
        if (status[k]) {
            if (dir[k] == 0 && !changeDir[k]) {
                moveLeft(time, k);
                ++k;
            } else {
                if (dir[k] == 1 && !changeDir[k]) {
                    moveRight(time, k);
                    ++k;
                } else {
                    if (dir[k] == 2 && !changeDir[k]) {
                        moveUp(time, k);
                        ++k;
                    } else {
                        if (dir[k] == 3 && !changeDir[k]) {
                            moveDown(time, k);
                            ++k;
                        } else {
                            if (changeDir[k]) {
                                discretization(time, k);
                                ++k;
                            }
                        }
                    }
                }
            }
            collisionDetection(k-1);
            window.draw(sprite);
        }else {
            ++k;
        }
    }
}


 void Player::moveLeft(float &time) {
    dx = -0.2;
    dy = 0;
    rect.left += dx*time;
    if (rect.left < 0) {
        rect.left = 0;
        dx = 0;
    }
    currentFrame += 0.01*time;
    if (currentFrame > 2) currentFrame -= 2;
    sprite.setTextureRect(IntRect(60*int(currentFrame)+40,0,-40,50));
    sprite.setPosition(rect.left, rect.top);
    bomb->changeStatus(rect);
}

 void Player::moveRight(float &time) {
    dx = 0.2;
    dy = 0;
    rect.left += dx*time;
    if (rect.left > Width - 40) {
        rect.left = Width - 40;
        dx = 0;
    }
    currentFrame += 0.01*time;
    if (currentFrame > 2) currentFrame -= 2;
    sprite.setTextureRect(IntRect(60*int(currentFrame),0,40,50));
    sprite.setPosition(rect.left, rect.top);
    bomb->changeStatus(rect);
}

 void Player::moveUp(float &time) {
    dy = -0.2;
    dx = 0;
    rect.top += dy*time;
    if (rect.top < 0) {
        rect.top = 0;
        dy = 0;
    }
    currentFrame += 0.01*time;
    if (currentFrame > 2) currentFrame -= 2;
    sprite.setTextureRect(IntRect(60*int(currentFrame)+152,0,-40,50));
    sprite.setPosition(rect.left, rect.top);
    bomb->changeStatus(rect);
}

 void Player::moveDown(float &time) {
    dy = 0.2;
    dx = 0;
    rect.top += dy*time;
    if (rect.top > Heigth - 50) {
        rect.top = Heigth - 50;
        dy = 0;
    }
    currentFrame += 0.01*time;
    if (currentFrame > 3) currentFrame -= 3;
    sprite.setTextureRect(IntRect(60*int(currentFrame)+263,0,-40,50));
    sprite.setPosition(rect.left, rect.top);
    bomb->changeStatus(rect);
}

 void Player::discretization(float &time) {
    if (dx < 0) {
        if (fabs( fabs(rect.left - (int(rect.left/55))*55) - 7.5 ) < 2 ) {
            dx = 0;
            rect.left = int(rect.left/55)*55 + 7.5;
            sprite.setPosition(rect.left, rect.top);
            sprite.setTextureRect(IntRect(60+205,0,-40,50));
        } else {
            moveLeft(time);
        }
    } else {
        if (dx > 0) {
            if (fabs( fabs(rect.left - (int(rect.left/55))*55) - 7.5 ) < 2 ) {
                dx = 0;
                rect.left = int(rect.left/55)*55 + 7.5;
                sprite.setPosition(rect.left, rect.top);
                sprite.setTextureRect(IntRect(60+205,0,-40,50));
            } else {
                moveRight(time);
            }
        } else {
            if (dy < 0) {
                if (fabs( fabs(rect.top - (int(rect.top/55))*55) - 2.5 ) < 2 ) {
                    dy = 0;
                    rect.top = int(rect.top/55)*55 + 2.5;
                    sprite.setPosition(rect.left, rect.top);
                    sprite.setTextureRect(IntRect(60+205,0,-40,50));
                } else {
                    moveUp(time);
                }
            } else {
                if (dy > 0) {
                    if (fabs( fabs(rect.top - (int(rect.top/55))*55) - 7.5 ) < 2 ) {
                        dy = 0;
                        rect.top = int(rect.top/55)*55 + 2.5;
                        sprite.setPosition(rect.left, rect.top);
                        sprite.setTextureRect(IntRect(60+205,0,-40,50));
                    } else {
                        moveDown(time);
                    }
                } else {
                    sprite.setTextureRect(IntRect(60+205,0,-40,50));
                }
            }
        }
    }




}

 void Player::collisionDetection() {
    for (int i = rect.top/55; i < (rect.top + rect.height)/55; i++) {
        for (int j = rect.left/55; j < (rect.left + rect.width)/55; j++) {
            if (i < amountHeight && j < amountWidth) {
                if(TileMap[i][j] == 'P' || TileMap[i][j] == 'K' || TileMap[i][j] == 'B'
                        || TileMap[i][j] == 'c' || TileMap[i][j] == 'v') {
                    if (dx > 0) {
                        rect.left = j * 55 - rect.width;
                        dx = 0;
                    }
                    if (dx < 0) {
                        rect.left = j * 55 + 55;
                        dx = 0;
                    }
                    if (dy > 0) {
                        rect.top = i * 55 - rect.height;
                        dy = 0;
                    }
                    if (dy < 0) {
                        rect.top = i * 55 + 55;
                        dy = 0;
                    }
                }
            }

        }
    }
}

 void Player::botCollisionDetection() {
    for (int i = 0; i < numberBot; i++) {
        if (bot->status[i]) {
            if (fabs(rect.left - bot->rect[i].left) < 27 && fabs(rect.top - bot->rect[i].top) < 27) {
                status = false;
                break;
            }
        }
    }
}

 void Player::action(float &time){
    if(status) {
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            moveLeft(time);
        } else {
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                moveRight(time);
            } else {
                if (Keyboard::isKeyPressed(Keyboard::Up)) {
                    moveUp(time);
                } else {
                    if (Keyboard::isKeyPressed(Keyboard::Down)) {
                        moveDown(time);
                    } else {
                        discretization(time);
                        if (Keyboard::isKeyPressed(Keyboard::Space)) {
                            bomb->setBomb(rect.top/55, rect.left/55);
                        }
                        if (Keyboard::isKeyPressed(Keyboard::Return)) {
                            if (bomb->status) {
                                TileMap[bomb->i][bomb->j] = 'A';
                                bomb->currentFrame = 0.0;
                            }
                        }
                    }
                }
            }
        }
        collisionDetection();
        botCollisionDetection();
    } else {
        sprite.setTextureRect(IntRect(400,0, 55,55));
        sprite.setPosition(rect.left, rect.top);
    }
}

void KeyAndDoor::randomSetPosition() {
    srand(time(NULL));
    while (true) {
        iKey = rand()%13;
        jKey = rand()%23;
        if (TileMap[iKey][jKey] == ' ' && ((iKey != 8 && iKey != 9) || (jKey != 1 && jKey != 2 && jKey != 3) )) {
            TileMap[iKey][jKey] = 'c';
            break;
        }
    }
    while (true) {
        iDoor = rand()%13;
        jDoor = rand()%23;
        if (TileMap[iDoor][jDoor] == ' ' && ((iDoor != 8 && iDoor != 9) || (jDoor != 1 && jDoor != 2 && jDoor != 3) )) {
            TileMap[iDoor][jDoor] = 'v';
            break;
        }
    }
}


void Bot::randomSetPosition() {
    int k = 0;
    srand(time(NULL));
    while (k < numberBot) {
        i[k] = rand()%13;
        j[k] = rand()%23;
        if (TileMap[i[k]][j[k]] == ' ' && ((i[k] != 8 && i[k] != 9) || (j[k] != 1 && j[k] != 2 && j[k] != 3) )) {
            TileMap[i[k]][j[k]] = 'D';
            rect[k].left = j[k]*55;
            rect[k].top = i[k]*55;
            ++k;
        }
    }
}
