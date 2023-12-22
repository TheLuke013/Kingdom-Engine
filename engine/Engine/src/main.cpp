#include "Game.h"
#include <windows.h>

int main()
{
	HWND hwndGodot = FindWindow(L"GodotWindowClass", L"Godot Game");
	HWND hwndProcess = CreateWindow(L"SubprocessWindowClass", L"Subprocess", WS_OVERLAPPEDWINDOW, 0, 0, 640, 480, NULL, NULL, NULL, NULL);

	SetParent(hwndProcess, hwndGodot);

	Game game;
	game.initGame("My Game", 640, 480);
	game.startLoop();

	return 0;
}