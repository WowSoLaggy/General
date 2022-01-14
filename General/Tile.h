#pragma once

#include "Object.h"


class Tile : public Object
{
public:
  Tile();

  void setCoords(Sdk::Vector2I i_coords);
  const Sdk::Vector2I& getCoords() const;

  virtual Sdk::Vector3F getPosition() const override;

private:
  Sdk::Vector2I d_coords;
  float d_xPosOffset = 0.0f;
};
