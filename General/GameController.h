#pragma once

#include "Fwd.h"

#include <LaggySdk/EventHandler.h>


class GameController : public Sdk::EventHandler
{
public:
  GameController(Game& i_game);

  virtual void processEvent(const Sdk::IEvent& i_event) override;

  void onNewGameClick() const;
  void onExitClick() const;

  void tryPickObject();
  void pickObject(const Object& i_object);
  void unpickObject();
  bool isObjectPicked() const;

private:
  Game& d_game;
  const Object* d_pickedObject = nullptr;
};
