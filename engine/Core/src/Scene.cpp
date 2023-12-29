#include "Scene.h"

Scene::Scene(std::string sceneName)
{
    this->sceneName = sceneName;
}

std::string Scene::GetSceneName()
{
    return sceneName;
}