#include "stdafx.h"
#include "SessionView.h"

#include "Game.h"

#include <LaggyDx/ICamera.h>
#include <LaggyDx/ISimpleRenderer.h>
#include <LaggySdk/Math.h>


SessionView::SessionView(Game& i_game)
  : d_camera(Dx::ICamera::createCamera(i_game.getRenderDevice().getResolution()))
  , d_simpleRenderer(Dx::ISimpleRenderer::getOrCreate(
      i_game.getRenderDevice(), *d_camera, i_game.getResourceController()))
  , d_session(i_game.getSession())
  , d_tileView(i_game.getResourceController())
{
  d_camera->setUp({ 0.0f, 0.0f, 1.0f });
  d_camera->setLookAt({ 0.0f, 0.0f, 0.0f });
  d_camera->setDistance(10.0f);
  d_camera->setYaw(Sdk::degToRad(-90.0f));
  d_camera->setPitch(Sdk::degToRad(45.0f));
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
