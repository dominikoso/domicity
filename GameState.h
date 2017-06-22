//
// Created by dominikoso on 14.01.17.
//

#ifndef DOMICITY_GAMESTATE_H
#define DOMICITY_GAMESTATE_H

#include "Game.h"

class GameState
{
public:

    Game* game;

    virtual void draw(const float dt) = 0; //drawing game, idk how to make it clear
    virtual void update(const float dt) = 0; //Update the GameState - chcecking state, controling systems etc.
    virtual void handleInput() = 0;
};

#endif /* DOMICITY_GAMESTATE_H */
