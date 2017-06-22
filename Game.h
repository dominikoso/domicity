//
// Created by dominikoso on 22.12.16.
//

#ifndef DOMICITY_GAME_H
#define DOMICITY_GAME_H

#include <map>
#include <string>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureManager.h"
#include "Tile.h"
#include "gui.h"

class GameState;

class Game
{

private:

    void loadTextures();
    void loadTiles();
    void loadStylesheets();
    void loadFonts();
    void pause();

public:

    std::stack<GameState*> states;

    const static int tileSize = 8;

    sf::RenderWindow window;
    TextureManager texmgr;
    sf::Sprite background;

    std::map<std::string, Tile> tileAtlas;
    std::map<std::string, GuiStyle> stylesheets;
    std::map<std::string, sf::Font> fonts;


    void pushState(GameState* state); //Status Print
    void popState();
    void changeState(GameState* state); //Status Control
    GameState* peekState();

    void gameLoop();

    Game();
    ~Game();
};
#endif /* DOMICITY_GAME_H */
