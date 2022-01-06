#include "stdafx.h"
#include "Game.h"

#include "GameEvents.h"
#include "Session.h"

#include <LaggyDx/GameSettings.h>


namespace
{
  const Dx::GameSettings& getGameSettings()
  {
    static const Dx::GameSettings gameSettings{ 1600, 900, "General", "Data/Assets/" };
    return gameSettings;
  }

} // anon NS


Game::Game()
  : Dx::Game(getGameSettings())
{
  getInputDevice().showCursor();

  attachController();
  notify(GameStartedEvent());
}


void Game::update(double i_dt)
{
  if (d_session)
    d_session->update(i_dt);
  if (d_sessionView)
    d_sessionView->update(i_dt);

  Dx::Game::update(i_dt);
}


void Game::render()
{
  if (d_sessionView)
    d_sessionView->render();

  Dx::Game::render();
}


void Game::attachController()
{
  d_controller = std::make_unique<GameController>(*this);
}

void Game::attachSession(std::unique_ptr<Session> i_session)
{
  d_session = std::move(i_session);
}

void Game::attachSessionView()
{
  d_sessionView = std::make_unique<SessionView>(*this);
}


Session& Game::getSession() const
{
  CONTRACT_ASSERT(d_session);
  return *d_session;
}

SessionView& Game::getSessionView() const
{
  CONTRACT_ASSERT(d_sessionView);
  return *d_sessionView;
}
