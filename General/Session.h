#pragma once

#include "Fwd.h"
#include "SessionView.h"


class Session
{
public:
  std::vector<std::shared_ptr<Tile>>& getTiles();
  const std::vector<std::shared_ptr<Tile>>& getTiles() const;

  std::vector<std::shared_ptr<Object>>& getObjects();
  const std::vector<std::shared_ptr<Object>>& getObjects() const;

  void update(double i_dt);

private:
  std::vector<std::shared_ptr<Tile>> d_tiles;
  std::vector<std::shared_ptr<Object>> d_objects;
};
