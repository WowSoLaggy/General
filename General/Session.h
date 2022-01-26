#pragma once

#include "Fwd.h"
#include "SessionView.h"


class Session
{
public:
  std::shared_ptr<Object>& getBackground();
  const std::shared_ptr<Object>& getBackground() const;

  std::vector<std::shared_ptr<Tile>>& getTiles();
  const std::vector<std::shared_ptr<Tile>>& getTiles() const;

  std::vector<std::shared_ptr<Object>>& getObjects();
  const std::vector<std::shared_ptr<Object>>& getObjects() const;

  void update(double i_dt);

private:
  std::shared_ptr<Object> d_background;
  std::vector<std::shared_ptr<Tile>> d_tiles;
  std::vector<std::shared_ptr<Object>> d_objects;
};
