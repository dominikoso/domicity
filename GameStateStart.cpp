//
// Created by dominikoso on 14.01.17.
//

#include <SFML/Graphics.hpp>

#include "GameStateStart.h"
#include "GameStateEditor.h"
#include "GameState.h"

GameStateStart::GameStateStart(Game* game)
{
    this->game = game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);

    this->guiSystem.emplace("menu", Gui(sf::Vector2f(192, 32), 4, false, game->stylesheets.at("button"),
                                        { std::make_pair("Load Config", "load_game") }));

    this->guiSystem.emplace("exit", Gui(sf::Vector2f(192, 32), 4, false, game->stylesheets.at("button"),
                                        { std::make_pair("Exit Game", "exit_game") }));

    this->guiSystem.at("menu").setPosition(pos);
    this->guiSystem.at("exit").setPosition(pos.x, pos.y + 250);
    this->guiSystem.at("menu").setOrigin(96, 32*1/2);
    this->guiSystem.at("exit").setOrigin(96, 32*1/2);
    this->guiSystem.at("menu").show();
    this->guiSystem.at("exit").show();
    this->musicStart();
}

void GameStateStart::loadgame()
{
    this->game->pushState(new GameStateEditor(this->game));

    return;
}

void GameStateStart::draw(const float dt)
{
    this->game->window.setView(this->view);

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    for(auto gui : this->guiSystem) this->game->window.draw(gui.second);


    return;
}

void GameStateStart::update(const float dt)
{
}

void GameStateStart::handleInput()
{
    sf::Event event;

    sf::Vector2f mousePos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->view);

    while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
            /* Close the window. */
            case sf::Event::Closed:
            {
                game->window.close();
                break;
            }
                /* Resize the window. */
            case sf::Event::Resized:
            {
                this->view.setSize(event.size.width, event.size.height);
                this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->view));
                sf::Vector2f pos = sf::Vector2f(event.size.width, event.size.height);
                pos *= 0.5f;
                pos = this->game->window.mapPixelToCoords(sf::Vector2i(pos), this->view);
                this->guiSystem.at("menu").setPosition(pos);
                this->game->background.setScale(
                        float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                        float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
                break;
            }
                /* Highlight menu items. */
            case sf::Event::MouseMoved:
            {
                this->guiSystem.at("menu").highlight(this->guiSystem.at("menu").getEntry(mousePos));
                this->guiSystem.at("exit").highlight(this->guiSystem.at("exit").getEntry(mousePos));
                break;
            }
                /* Click on menu items. */
            case sf::Event::MouseButtonPressed:
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    std::string msg = this->guiSystem.at("menu").activate(mousePos);
                    std::string msg2 = this->guiSystem.at("exit").activate(mousePos);

                    if(msg == "load_game")
                    {
                        this->loadgame();
                    }
                    if(msg2 == "exit_game")
                    {
                        game->window.close();
                    }
                }
                break;
            }
            case sf::Event::KeyPressed:
            {
                if(event.key.code == sf::Keyboard::Escape) this->game->window.close();
                break;
            }
            default: break;
        }
    }

    return;
}

void GameStateStart::musicStart() {

    if(!bgm.openFromFile("media/bgm.ogg")){

        std::cerr << "BGM not found, continuing without";
    }

    bgm.play();
    bgm.setLoop(true);

}