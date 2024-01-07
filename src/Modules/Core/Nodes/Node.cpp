#include "Node.h"
#include <Game.h>

// construtor
Node::Node(const std::string &name) : nodeName(name), node(nullptr)
{
    node = Game::GetSceneManager()->GetSceneManager()->addEmptySceneNode();
}

//obtem o node raiz
irr::scene::ISceneNode* Node::GetNode()
{
    return node;
}

// obtem uma string com nome do node
std::string Node::GetNodeName() const
{
    return nodeName;
}

//obtem uma string com tipo do node
std::string Node::GetNodeType() const
{
    return nodeType;
}

//define o tipo do node
void Node::SetNodeType(const std::string& nodeType)
{
    this->nodeType = nodeType;
}

//adiciona o node a cena atual
void Node::AddNode()
{
    Game::GetSceneManager()->GetCurrentScene()->AddNode(this);
}

//altera a posicao tridimensional do Node
void Node::SetPosition(float x, float y, float z)
{
    //verifica se o node foi instanciado
    if (node)
        node->setPosition(irr::core::vector3df(x, y, z));
    else
        std::cout << "Node nao foi instanciado" << std::endl;
}

//altera a rotacao tridimensional do Node
void Node::SetRotation(float x, float y, float z)
{
    //verifica se o node foi instanciado
    if (node)
        node->setRotation(irr::core::vector3df(x, y, z));
    else
        std::cout << "Node nao foi instanciado" << std::endl;
}

//altera a escala tridimensional do Node
void Node::SetScale(float x, float y, float z)
{
    //verifica se o node foi instanciado
    if (node)
        node->setScale(irr::core::vector3df(x, y, z));
    else
        std::cout << "Node nao foi instanciado" << std::endl;
}

//altera a posicao bidimensional do Node
void Node::SetPosition2D(float x, float y)
{
    //verifica se o node foi instanciado
    if (node)
        node->setPosition(irr::core::vector3df(x, y, 0.0f));
    else
        std::cout << "Node nao foi instanciado" << std::endl;
}

//altera a rotacao bidimensional do Node
void Node::SetRotation2D(float angle)
{
    //verifica se o node foi instanciado
    if (node)
        node->setRotation(irr::core::vector3df(0.0f, 0.0f, angle));
    else
        std::cout << "Node nao foi instanciado" << std::endl;
}

//altera a escala bidimensional do Node
void Node::SetScale2D(float x, float y)
{
    //verifica se o node foi instanciado
    if (node)
        node->setScale(irr::core::vector3df(x, y, 1.0f));
    else
        std::cout << "Node nao foi instanciado" << std::endl;
}
