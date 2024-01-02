#ifndef SPRITE_H
#define SPRITE_H

#include "Node.h"

class Sprite : public Node
{
private:
    irr::video::ITexture* texture; //textura do sprite

public:
    Sprite(const std::string& name) : Node(name) {};

    void SetTexture(const std::string& textureName);

};

#endif