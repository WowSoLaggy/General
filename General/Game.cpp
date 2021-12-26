#include "stdafx.h"
#include "Game.h"

#include <LaggyDx/GameSettings.h>


namespace
{
  const Dx::GameSettings& getGameSettings()
  {
    static const Dx::GameSettings gameSettings{ 1600, 900, "General", "Data/Assets/" };
    return gameSettings;
  }

} // anon NS


Game::Game() : Dx::Game(getGameSettings())
{
}
