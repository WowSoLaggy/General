#include "stdafx.h"
#include "GameController.h"

#include "CreateSession.h"
#include "Game.h"
#include "GameEvents.h"
#include "MenuCreator.h"


GameController::GameController(Game& i_game)
  : d_game(i_game)
  , d_menuCreator(*this, d_game.getRenderDevice().getResolution())
{
  connectTo(d_game);
}


void GameController::processEvent(const Sdk::IEvent& i_event)
{
  if (dynamic_cast<const GameStartedEvent*>(&i_event))
    showMainMenu();
}


void GameController::showMainMenu()
{
  d_menuCreator.clearAll(d_game.getForm());
  d_menuCreator.createMainMenu(d_game.getForm());
}


void GameController::onNewGameClick()
{
  d_menuCreator.clearAll(d_game.getForm());

  d_game.attachSession(createSession());
  d_game.attachSessionView();
}

void GameController::onExitClick()
{
  d_game.stop();
}
