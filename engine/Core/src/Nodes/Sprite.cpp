#include "Sprite.h"
#include "../Game.h"

//altera/define a textura do Sprite
void Sprite::SetTexture(const std::string& textureName)
{
    //obtem o video driver da engine
    irr::video::IVideoDriver* videoDriver = Game::GetSceneManager()->GetSceneManager()->getVideoDriver();
    //verifica se o video driver esta ativo
    if (videoDriver)
    {
        texture = videoDriver->getTexture(textureName.c_str());
    }
}

void Sprite::Render() const
{
    //obtem o video driver da engine
    irr::video::IVideoDriver* videoDriver = Game::GetSceneManager()->GetSceneManager()->getVideoDriver();
    if (videoDriver)
    {
        //desenha o sprite na tela
        videoDriver->draw2DImage(texture, position,
            irr::core::recti(0, 0, texture->getOriginalSize().Width,
            texture->getOriginalSize().Height),
            0, irr::video::SColor(255, 255, 255, 255), true);
    }
}