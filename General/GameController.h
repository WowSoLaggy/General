#pragma once

#include "Fwd.h"

#include <LaggySdk/EventHandler.h>


class GameController : public Sdk::EventHandler
{
public:
  GameController(Game& i_game);

  virtual void processEvent(const Sdk::IEvent& i_event) override;

private:
  Game& d_game;

  void showMainMenu();

  void onNewGameClick();
  void onExitClick();
};
