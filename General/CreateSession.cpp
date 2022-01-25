#include "stdafx.h"
#include "CreateSession.h"

#include "PrototypeCollection.h"
#include "Tile.h"


namespace
{
  void createMap(Session& i_session)
  {
    auto& tiles = i_session.getTiles();
    auto createTile = [&](const int i_x, const int i_y) -> Tile&
    {
      auto tilePtr = std::make_shared<Tile>();
      tiles.push_back(tilePtr);
      auto& tile = *tilePtr;

      tile.setCoords({ i_x, i_y });

      return tile;
    };

    constexpr int mapSizeX = 3;
    constexpr int mapSizeY = 3;
    for (int y = 0; y < mapSizeY; ++y)
    {
      const int sizeXModified = y % 2 == 1 ? mapSizeX - 1 : mapSizeX;
      for (int x = 0; x < sizeXModified; ++x)
        auto& tile = createTile(x, y);
    }
  }

  void createObjects(Session& i_session)
  {
    auto tank = std::make_shared<Object>(PrototypeCollection::get("tank"));
    tank->setAnimation("idle", true);
    i_session.getObjects().push_back(std::move(tank));
  }

} // anonym NS


std::unique_ptr<Session> createSession()
{
  auto session = std::make_unique<Session>();
  
  createMap(*session);
  createObjects(*session);

  return session;
}
