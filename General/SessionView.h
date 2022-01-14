#pragma once

#include "CameraController.h"
#include "Fwd.h"
#include "View.h"

#include <LaggyDx/LaggyDxFwd.h>


class SessionView
{
public:
  SessionView(Game& i_game);

  CameraController& getCameraController();
  const CameraController& getCameraController() const;

  void render();
  void update(double i_dt);

private:
  CameraController d_cameraController;
  Dx::ISimpleRenderer& d_simpleRenderer;

  Session& d_session;

  View d_view;
};
