//
// Created by dominikoso on 14.01.17.
//

#ifndef DOMICITY_GAMESTATESTART_H
#define DOMICITY_GAMESTATESTART_H
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "gui.h"
#include "GameState.h"

class GameStateStart : public GameState
{
private:

    sf::View view;

    sf::Music bgm;

    std::map<std::string, Gui> guiSystem;

    void loadgame();

    void musicStart();

public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateStart(Game* game);
};


#endif /* DOMICITY_GAMESTATESTART_H */
