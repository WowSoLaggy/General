#include "stdafx.h"
#include "CreateSession.h"

#include "PrototypeCollection.h"
#include "Tile.h"
#include "TileGridSettings.h"


namespace
{
  void createBackground(Session& i_session, const int i_mapSizeX, const int i_mapSizeY)
  {
    auto background = std::make_shared<Object>(PrototypeCollection::get("map"));

    const float middleX = (i_mapSizeX - 1) * TileGridSettings::TileOffsetX / 2;
    const float middleY = (i_mapSizeY - 1) * TileGridSettings::TileOffsetY / 2;

    const float scaleX = i_mapSizeX * TileGridSettings::TileOffsetX / 2;
    const float scaleY = i_mapSizeY * TileGridSettings::TileOffsetY / 2;

    background->setPosition({ middleX, middleY, -0.1f });
    background->setScale({ scaleX, scaleY, 1 });

    i_session.getBackground() = std::move(background);
  }

  void createMap(Session& i_session, const int i_mapSizeX, const int i_mapSizeY)
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

    for (int y = 0; y < i_mapSizeY; ++y)
    {
      const int sizeXModified = y % 2 == 1 ? i_mapSizeX - 1 : i_mapSizeX;
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
  
  constexpr int MapSizeX = 3;
  constexpr int MapSizeY = 3;

  createBackground(*session, MapSizeX, MapSizeY);
  createMap(*session, MapSizeX, MapSizeY);
  createObjects(*session);

  return session;
}
