#ifndef SPRITE_H
#define SPRITE_H

#include "Node.h"

class Sprite : public Node
{
private:
    irr::scene::IBillboardSceneNode* spriteNode; //Node do sprite
    irr::video::SMaterial material; //material do sprite
    irr::core::vector2d<irr::s32> spritePosition; //posicao do sprite

public:
    //construtor
    Sprite(const std::string& name);
    virtual ~Sprite() override = default; //destrutor virtual

    //metodo virtual/override de renderizacao do Sprite
    virtual void Render() override;

    //getters e setters
    void SetTexture(const std::string& textureName);
    void SetPosition(float x, float y);
    void SetRotation(float angle);
    void SetScale(float x, float y);

};

#endif