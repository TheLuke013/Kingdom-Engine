#define NOMINMAX

#include "Sprite.h"
#include <Game.h>

//construtor
Sprite::Sprite(const std::string& name) : Node(name)
{
    //inicializa o Node Sprite e o adiciona como filho do node raiz
    //spriteNode = Game::GetSceneManager()->GetSceneManager()->addBillboardSceneNode(GetNode());
    //material.Lighting = false; //material nao precisa de uma luz

    //irr::scene::ICameraSceneNode* camera = Game::GetSceneManager()->GetSceneManager()->addCameraSceneNode(0, irr::core::vector3df(0, 0, 40), irr::core::vector3df(0, 0, 0));

    SetNodeType("Sprite"); //define o tipo do Node
    //spritePosition = irr::core::vector2d<irr::s32>(0, 0); //inicializa a posicao do Sprite
}

//altera/define a textura do Sprite
void Sprite::SetTexture(const std::string& textureName)
{
    //obtem o video driver da engine
    //irr::video::IVideoDriver* videoDriver = Game::GetSceneManager()->GetSceneManager()->getVideoDriver();
    //verifica se o video driver esta ativo
   // if (videoDriver)
    //{
    //    material.setTexture(0, videoDriver->getTexture(textureName.c_str()));
    //    spriteNode->getMaterial(0) = material;
    //}
}

void Sprite::SetPosition(float x, float y)
{
    SetPosition2D(x, y);
}

void Sprite::SetRotation(float angle)
{
    SetRotation2D(angle);
}

void Sprite::SetScale(float x, float y)
{
    SetScale2D(x, y);
}

//renderiza o Sprite na tela
void Sprite::Render()
{
    //obtem o video driver da engine
    //irr::video::IVideoDriver* videoDriver = Game::GetSceneManager()->GetSceneManager()->getVideoDriver();
    //verifica se videoDriver esta ativo
    //if (videoDriver)
   // {
    //    spriteNode->updateAbsolutePosition();
    //    GetNode()->updateAbsolutePosition();
    //    Game::GetSceneManager()->GetSceneManager()->drawAll();
    //}
    //else
    //{
    //    std::cerr << "Nao foi encontrado d Driver Video" << std::endl;
    //}
}