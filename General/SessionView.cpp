#include "stdafx.h"
#include "SessionView.h"

#include "CameraController.h"
#include "Game.h"
#include "Tile.h"

#include <LaggyDx/ISimpleRenderer.h>


SessionView::SessionView(Game& i_game)
  : d_simpleRenderer(Dx::ISimpleRenderer::getOrCreate(
      i_game.getRenderDevice(), d_cameraController.getCamera(), i_game.getResourceController()))
  , d_session(i_game.getSession())
  , d_view(i_game.getResourceController())
{
}


CameraController& SessionView::getCameraController()
{
  return d_cameraController;
}

const CameraController& SessionView::getCameraController() const
{
  return d_cameraController;
}


void SessionView::render()
{
  for (const auto& tilePtr : d_session.getTiles())
  {
    d_view.setObject(*tilePtr);
    d_simpleRenderer.draw(d_view);
  }

  for (const auto& objPtr : d_session.getObjects())
  {
    d_view.setObject(*objPtr);
    d_simpleRenderer.draw(d_view);
  }
}

void SessionView::update(double i_dt)
{
  d_cameraController.update(i_dt);
}
