//
// Created by dominikoso on 14.01.17.
//

#ifndef DOMICITY_GAMESTATEEDITOR_H
#define DOMICITY_GAMESTATEEDITOR_H
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "map.h"
#include "Tile.h"
#include "GameState.h"
#include "gui.h"
#include "cityController.h"

enum class ActionState { NONE, PANNING, SELECTING };

class GameStateEditor : public GameState
{
private:

    ActionState actionState;

    sf::View gameView;
    sf::View guiView;

    City city;

    sf::Vector2i panningAnchor;
    float zoomLevel;
    bool paused;

    sf::Vector2i selectionStart;
    sf::Vector2i selectionEnd;

    Tile* currentTile;

    std::map<std::string, Gui> guiSystem;

public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateEditor(Game* game);
};

#endif //DOMICITY_GAMESTATEEDITOR_H
