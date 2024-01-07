# Project

## project.kep
```ini
[WindowSettings]
Title=Game1
ScreenWidth=1024
ScreenHeight=600
BackgroundColor=(255, 0, 0, 0)
FullScreen=0
VSync=0
FPSLimit=60.0

[GameSettings]
DebugMode=0
MainScene=PlayerScene
```
### Keys and values
- `Title: std::string` <br>
    Desription:
    the title of the game window

- `ScreenWidth: int` <br>
  Desription: the width of the game window

- `ScreenHeight: int` <br>
  Desription:
  the height of the game window

- `MainScene: std::string` <br>
  Desription:
  main scene that will start when running the game

- `BackgroundColor: Color{int r, int g, int b, int a}` <br>
  Desription:
  the background color of the game window

- `FullScreen: bool` <br>
  Desription:
  enable/disable full screen when starting

- `VSync: bool` <br>
  Desription:
  enable/disable vsync when starting

- `FPSLimit: float` <br>
  Desription:
  sets the FPS limit at which the game renders

- `DebugMode: bool` <br>
  Desription:
  print debug messages

- `MainScene: std::string` <br>
  Desription:
  defines the main scene by its name