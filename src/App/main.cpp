#include "App.h"

int main(int argc, char *argv[])
{
    //instancia da engine
    KingdomEngine::App engine;
    //inicializa a engine e o opengl
    engine.InitEngine(argc, argv);
    //inicializa o loop da engine
    engine.Run();

    return 0;
}
