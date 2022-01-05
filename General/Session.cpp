#include "stdafx.h"
#include "Session.h"


std::vector<std::shared_ptr<Tile>>& Session::getTiles()
{
  return d_tiles;
}

const std::vector<std::shared_ptr<Tile>>& Session::getTiles() const
{
  return d_tiles;
}


void Session::update(double i_dt)
{
}
