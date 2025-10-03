#include "../includes/button.hpp"
#include "../includes/game.hpp"
#include "../includes/gamemanager.hpp"
#include "../includes/raylib.h"
#include "../includes/screenmanager.hpp"
#include "../includes/texturemanager.hpp"
int main() {

  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Vamos los gallos");
  /*
  Deck si;
  Game game;
  TextureManager java;
  ScreenManager hola(game);
  SetTargetFPS(60);

  Button jinou(0, 0, 100, 100, "jinou", RED, GREEN, BLUE,
               java.getTexture(si.at(10).toString()));

  */

  GameManager Engine;

  while (!WindowShouldClose() &&
         !Engine.getContext()
              .closeRequest) // Detect window close button or ESC key
  {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    // hola.pushScreen(std::make_unique<MainMenuScreen>());
    // jinou.drawButton();

    Engine.getScreenManager().pushScreen(std::make_unique<MainMenuScreen>());
    Engine.getScreenManager().run();

    DrawText("Los gallos muy gallos", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
  }
  Engine.unload();
  CloseWindow();

  // game.run();

  return 0;
}
