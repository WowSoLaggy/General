#pragma once

#include "Fwd.h"
#include "MenuCreator.h"

#include <LaggyDx/LaggyDxFwd.h>


class Gui
{
public:
  Gui(Game& i_game);

  void showMainMenu();
  void hideMainMenu();

  void switchDebugMenu();
  void showDebugMenu();
  void hideDebugMenu();

private:
  Game& d_game;
  MenuCreator d_menuCreator;

  std::shared_ptr<Dx::IControl> d_debugMenu;

  bool d_debugMenuShown = false;
};
