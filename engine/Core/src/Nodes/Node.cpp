#include "Node.h"

// construtor
Node::Node(const std::string &name) : nodeName(name) {}

// obtem uma string com nome do node
std::string Node::GetNodeName() const
{
    return nodeName;
}

//altera a posicao tridimensional do Node
void Node::SetPosition(float x, float y, float z)
{
    if (node)
        node->setPosition(irr::core::vector3df(x, y, z));
}

//altera a rotacao tridimensional do Node
void Node::SetRotation(float x, float y, float z)
{
    if (node)
        node->setRotation(irr::core::vector3df(x, y, z));
}

//altera a escala tridimensional do Node
void Node::SetScale(float x, float y, float z)
{
    if (node)
        node->setScale(irr::core::vector3df(x, y, z));
}

//altera a posicao bidimensional do Node
void Node::SetPosition2D(float x, float y)
{
    if (node)
        node->setPosition(irr::core::vector3df(x, y, 0.0f));
}

//altera a rotacao bidimensional do Node
void Node::SetRotation2D(float angle)
{
    if (node)
        node->setRotation(irr::core::vector3df(0.0f, 0.0f, angle));
}

//altera a escala bidimensional do Node
void Node::SetScale2D(float x, float y)
{
    if (node)
        node->setScale(irr::core::vector3df(x, y, 1.0f));
}
