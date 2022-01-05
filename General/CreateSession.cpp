#include "stdafx.h"
#include "CreateSession.h"

#include "Tile.h"


std::unique_ptr<Session> createSession()
{
  auto session = std::make_unique<Session>();
  auto& tiles = session->getTiles();

  tiles.push_back(std::make_shared<Tile>());

  return session;
}
