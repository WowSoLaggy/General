#include "stdafx.h"
#include "SessionView.h"

#include "CameraController.h"
#include "Game.h"

#include <LaggyDx/ISimpleRenderer.h>


SessionView::SessionView(Game& i_game)
  : d_camera(CameraController::createDefaultCamera())
  , d_simpleRenderer(Dx::ISimpleRenderer::getOrCreate(
      i_game.getRenderDevice(), *d_camera, i_game.getResourceController()))
  , d_session(i_game.getSession())
  , d_tileView(i_game.getResourceController())
{
}


void SessionView::render()
{
  for (const auto tilePtr : d_session.getTiles())
  {
    d_tileView.setTile(*tilePtr);
    d_simpleRenderer.draw(d_tileView);
  }
}

void SessionView::update(double i_dt)
{
}
