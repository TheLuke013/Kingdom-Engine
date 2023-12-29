#ifndef SCENE_H
#define SCENE_H

#include "../../ThirdParty/Irrlicht/include/irrlicht.h"
#include <string>

class Scene
{
private:
    irr::scene::ISceneNode* rootNode;

    std::string sceneName;

public:
    Scene(std::string sceneName);

    std::string GetSceneName();
    void DrawScene();
};

#endif