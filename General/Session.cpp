#include "stdafx.h"
#include "Session.h"

#include "Object.h"
#include "Tile.h"


std::shared_ptr<Object>& Session::getBackground() { return d_background; }
const std::shared_ptr<Object>& Session::getBackground() const { return d_background; }

std::vector<std::shared_ptr<Tile>>& Session::getTiles() { return d_tiles; }
const std::vector<std::shared_ptr<Tile>>& Session::getTiles() const { return d_tiles; }

std::vector<std::shared_ptr<Object>>& Session::getObjects() { return d_objects; }
const std::vector<std::shared_ptr<Object>>& Session::getObjects() const { return d_objects; }


void Session::update(double i_dt)
{
  auto updateAll = [&](const auto& i_array)
  {
    for (auto obj : i_array)
      obj->update(i_dt);
  };

  updateAll(d_tiles);
  updateAll(d_objects);
}
