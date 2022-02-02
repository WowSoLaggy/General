#pragma once

#include "Fwd.h"

#include <LaggyDx/LaggyDxFwd.h>
#include <LaggySdk/Vector.h>


class MenuCreator
{
public:
  MenuCreator(Game& i_game);

  void clearAll(Dx::IControl& i_parent) const;
  void createMainMenu(Dx::IControl& i_parent) const;

  std::shared_ptr<Dx::IControl> createDebugMenu(Dx::IControl& i_parent) const;

private:
  Game& d_game;
};
