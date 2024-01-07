#ifndef NODE_H
#define NODE_H

#include <string>
#include <irrlicht.h>

class Node
{
private:
    std::string nodeName; //nome do node
    std::string nodeType;
    irr::scene::ISceneNode* node; //raiz do node

    //getters e setters
    void SetPosition(float x, float y, float z);
    void SetRotation(float x, float y, float z);
    void SetScale(float x, float y, float z);

protected:
    //getters e setters para subclasses 2D
    void SetPosition2D(float x, float y);
    void SetRotation2D(float angle);
    void SetScale2D(float x, float y);

public:
    Node(const std::string& name); //construtor
    virtual ~Node() = default; //destrutor virtual

    irr::scene::ISceneNode* GetNode();
    std::string GetNodeName() const;
    std::string GetNodeType() const;
    void SetNodeType(const std::string& nodeType);
    void AddNode();

    //metodo virtual de renderizacao do Node
    virtual void Render() = 0;
};

#endif