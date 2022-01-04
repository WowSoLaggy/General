#include "stdafx.h"
#include "SessionView.h"

#include "Game.h"


SessionView::SessionView(const Game& i_game)
  : d_camera(Dx::ICamera::createCamera(i_game.getRenderDevice().getResolution()))
  , d_simpleRenderer(i_game.getResourceController(), *d_camera)
{
}


void SessionView::render()
{
}
