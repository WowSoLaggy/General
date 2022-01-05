#pragma once

#include "SessionView.h"


class Session
{
public:
  std::vector<std::shared_ptr<Tile>>& getTiles();
  const std::vector<std::shared_ptr<Tile>>& getTiles() const;

  void update(double i_dt);

private:
  std::vector<std::shared_ptr<Tile>> d_tiles;
};
