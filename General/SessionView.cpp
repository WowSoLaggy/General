#include "stdafx.h"
#include "SessionView.h"

#include "CameraController.h"
#include "Game.h"
#include "Tile.h"
#include "TileGridSettings.h"
#include "TileView.h"

#include <LaggyDx/ISimpleRenderer.h>


SessionView::SessionView(Game& i_game)
  : d_cameraController(i_game)
  , d_simpleRenderer(Dx::ISimpleRenderer::getOrCreate(
      i_game.getRenderDevice(), d_cameraController.getCamera(), i_game.getResourceController()))
  , d_session(i_game.getSession())
  , d_resourceController(i_game.getResourceController())
  , d_backgroundView(*i_game.getSession().getBackground(), i_game.getResourceController())
{
  const auto& startLocation = d_session.getTile(d_session.getPlayerStartTile()).getPosition();
  d_cameraController.getCamera().setLookAt(startLocation);

  for (auto& tilePtr : d_session.getTiles())
    addView(*tilePtr);
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
  d_simpleRenderer.setDrawAabb(d_drawBb);

  d_simpleRenderer.draw(d_backgroundView);

  for (const auto& tileViewPtr : d_tileViews)
    tileViewPtr->render(d_simpleRenderer);

  d_simpleRenderer.setDrawAabb(false);
}


void SessionView::update(const double i_dt)
{
  d_cameraController.update(i_dt);

  for (auto& tileViewPtr : d_tileViews)
    tileViewPtr->update();
}


void SessionView::setDrawBb(const bool i_drawBb)
{
  d_drawBb = i_drawBb;
}


void SessionView::addView(Tile& i_tile)
{
  auto tileViewPtr = std::make_shared<TileView>(i_tile, d_resourceController);
  d_tileViews.push_back(std::move(tileViewPtr));
}
