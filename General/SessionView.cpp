#include "stdafx.h"
#include "SessionView.h"

#include "CameraController.h"
#include "Game.h"
#include "Tile.h"
#include "TileGridSettings.h"

#include <LaggyDx/ISimpleRenderer.h>


SessionView::SessionView(Game& i_game)
  : d_simpleRenderer(Dx::ISimpleRenderer::getOrCreate(
      i_game.getRenderDevice(), d_cameraController.getCamera(), i_game.getResourceController()))
  , d_session(i_game.getSession())
  , d_view(i_game.getResourceController())
{
  const auto& startLocation = d_session.getTile(d_session.getPlayerStartTile()).getPosition();
  d_cameraController.getCamera().setLookAt(startLocation);
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
  d_view.setObject(*d_session.getBackground());
  d_simpleRenderer.draw(d_view);

  for (const auto& tilePtr : d_session.getTiles())
    renderTile(*tilePtr);
}

void SessionView::renderTile(Tile& i_tile)
{
  d_view.setObject(i_tile);
  d_simpleRenderer.draw(d_view);

  for (const auto& structurePtr : i_tile.getStructures())
  {
    d_view.setObject(*structurePtr);
    d_simpleRenderer.draw(d_view);
  }

  for (const auto& armyPtr : i_tile.getArmies())
  {
    d_view.setObject(*armyPtr);
    d_simpleRenderer.draw(d_view);
  }
}


void SessionView::update(double i_dt)
{
  d_cameraController.update(i_dt);
}
