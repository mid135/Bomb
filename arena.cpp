#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <arena.h>
void Arena :: drawArena(RenderWindow &window) {
    //first commit
   for (int i = 0; i < amountHeight; i++) {
       for (int j = 0; j < amountWidth; j++) {
           if (TileMap[i][j] == 'P') sprite.setTextureRect(IntRect(0, 110, 55, 55));
           if (TileMap[i][j] == 'K' || TileMap[i][j] == 'c' || TileMap[i][j] == 'v') sprite.setTextureRect(IntRect(58, 110, 55, 55));
           if (TileMap[i][j] == 'C') sprite.setTextureRect(IntRect(58, 170, 55, 55));
           if (TileMap[i][j] == 'V') sprite.setTextureRect(IntRect(0, 170, 55, 55));
           if (TileMap[i][j] == ' ' || TileMap[i][j] == 'A' || TileMap[i][j] == 'b' || TileMap[i][j] == 'B'
                   || TileMap[i][j] == 'D') {
               sprite.setTextureRect(IntRect(400, 200, 55, 55));
           }

           sprite.setPosition(j*55, i*55);
           window.draw(sprite);
       }
   }
}
