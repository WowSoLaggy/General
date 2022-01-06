#pragma once

#include "Fwd.h"
#include "MenuCreator.h"

#include <LaggySdk/EventHandler.h>


class GameController : public Sdk::EventHandler
{
public:
  GameController(Game& i_game);

  virtual void processEvent(const Sdk::IEvent& i_event) override;

  void onNewGameClick();
  void onExitClick();

private:
  Game& d_game;
  MenuCreator d_menuCreator;

  void showMainMenu();
};
