#include "stdafx.h"
#include "GameController.h"

#include "ActionsController.h"
#include "CreateSession.h"
#include "Game.h"
#include "GameEvents.h"


GameController::GameController(Game& i_game)
  : d_game(i_game)
{
  connectTo(d_game);
}


void GameController::processEvent(const Sdk::IEvent& i_event)
{
  if (dynamic_cast<const GameStartedEvent*>(&i_event))
    d_game.getGui().showMainMenu();
}


void GameController::onNewGameClick()
{
  d_game.getGui().hideMainMenu();

  d_game.attachSession(createSession());
  d_game.attachSessionView();

  ActionsController().createActionsInGame(d_game);
}

void GameController::onExitClick()
{
  d_game.stop();
}
