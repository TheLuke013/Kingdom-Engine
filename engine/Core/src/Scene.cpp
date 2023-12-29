#include "Scene.h"

//construtor da classe
Scene::Scene(std::string sceneName)
{
    this->sceneName = sceneName;
}

//retorna o nome da cena
std::string Scene::GetSceneName()
{
    return sceneName;
}

//desenha a cena
void Scene::DrawScene()
{

}