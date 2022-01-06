#pragma once

#include "Fwd.h"

#include <LaggyDx/LaggyDxFwd.h>
#include <LaggySdk/Vector.h>


class MenuCreator
{
public:
  MenuCreator(GameController& i_gameController, Sdk::Vector2I i_resolution);

  void clearAll(Dx::IControl& i_parent) const;
  void createMainMenu(Dx::IControl& i_parent) const;

private:
  GameController& d_gameController;
  Sdk::Vector2I d_resolution;
};
