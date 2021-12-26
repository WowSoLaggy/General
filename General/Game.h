#pragma once

#include <LaggyDx/Game.h>
#include <LaggyDx/GameSettings.h>


namespace
{
  const Dx::GameSettings& getGameSettings()
  {
    static const Dx::GameSettings gameSettings{ 1600, 900, "General", "Data/Assets/" };
    return gameSettings;
  }

} // anon NS

class Game : public Dx::Game
{
public:
  Game() : Dx::Game(getGameSettings())
  {
  }

};
