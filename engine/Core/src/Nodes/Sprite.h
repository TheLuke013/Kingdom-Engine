#ifndef SPRITE_H
#define SPRITE_H

#include "Node.h"

class Sprite : public Node
{
private:
    irr::video::ITexture* texture; //textura do sprite
    irr::core::vector2d<irr::s32> position; //posicao do sprite
    irr::core::vector2d<irr::s32> rotation; //rotacao do sprite
    irr::core::vector2d<irr::s32> scale; //escala do sprite

public:
    //construtor
    Sprite(const std::string& name) : Node(name)
    {
        position = irr::core::vector2d<irr::s32>(0, 0);
        rotation = irr::core::vector2d<irr::s32>(0, 0);
        scale = irr::core::vector2d<irr::s32>(0, 0);
    };
    virtual ~Sprite() override = default; //destrutor virtual

    //metodo virtual/override de renderizacao do Sprite
    virtual void Render() const override;

    //getters e setters
    void SetTexture(const std::string& textureName);
    void SetPosition(float x, float y);
    void SetRotation(float angle);
    void SetScale(float x, float y);

};

#endif