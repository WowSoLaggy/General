#pragma once

#include "Fwd.h"
#include "TileView.h"

#include <LaggyDx/ICamera.h>
#include <LaggyDx/LaggyDxFwd.h>


class SessionView
{
public:
  SessionView(const Game& i_game);

  void render();
  void update(double i_dt);

private:
  std::unique_ptr<Dx::ICamera> d_camera;
  Dx::ISimpleRenderer& d_simpleRenderer;

  Session& d_session;

  TileView d_tileView;
};
