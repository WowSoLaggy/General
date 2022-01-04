#pragma once

#include "Fwd.h"

#include <LaggyDx/ICamera.h>
#include <LaggyDx/SimpleRenderer.h>


class SessionView
{
public:
  SessionView(const Game& i_game);

  void render();

private:
  std::unique_ptr<Dx::ICamera> d_camera;
  Dx::SimpleRenderer d_simpleRenderer;
};
