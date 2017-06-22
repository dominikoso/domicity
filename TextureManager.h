//
// Created by dominikoso on 14.01.17.
//

#ifndef DOMICITY_TEXTUREMANAGER_H
#define DOMICITY_TEXTUREMANAGER_H


#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
private:

    /* Array of textures used */
    std::map<std::string, sf::Texture> textures;

public:

    /* Add a texture from a file */
    void loadTexture(const std::string& name, const std::string &filename);

    /* Translate an id into a reference */
    sf::Texture& getRef(const std::string& texture);

    /* Constructor */
    TextureManager()
    {
    }
};



#endif /* DOMICITY_TEXTUREMANAGER_H */
