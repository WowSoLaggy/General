#include "stdafx.h"
#include "Tile.h"

#include "PrototypeCollection.h"
#include "TileGridSettings.h"


Tile::Tile()
  : Object(PrototypeCollection::get("tile"))
{
}


void Tile::setCoords(Sdk::Vector2I i_coords)
{
  d_coords = std::move(i_coords);

  const bool oddYRow = d_coords.y % 2 == 1;
  d_xPosOffset = oddYRow ? TileGridSettings::TileOffsetXForOddYRow : 0.0f;
}

const Sdk::Vector2I& Tile::getCoords() const
{
  return d_coords;
}


Sdk::Vector3F Tile::getPosition() const
{
  return {
    TileGridSettings::TileOffsetX * d_coords.x + d_xPosOffset,
    TileGridSettings::TileOffsetY * d_coords.y };
}
