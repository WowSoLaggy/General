#include "stdafx.h"
#include "ObjectPicker.h"

#include "Game.h"
#include "Tile.h"


ObjectPicker::ObjectPicker(const Game& i_game)
  : d_game(i_game)
{
}


Sdk::RayF ObjectPicker::castRay() const
{
  const auto mousePos = d_game.getInputDevice().getMousePosition();
  return d_game.getSessionView().getCameraController().getCamera().screenToWorld(mousePos);
}


const Object* ObjectPicker::pick() const
{
  const auto ray = castRay();

  auto intersect = [&](const Object& i_object) -> bool
  {
    if (const auto obbOpt = i_object.getObb())
      return obbOpt->intersect(ray);
    return false;
  };

  auto checkArray = [&](const auto& i_arr) -> const Object*
  {
    for (const auto& objPtr : i_arr)
    {
      if (intersect(*objPtr))
        return objPtr.get();
    }
    return nullptr;
  };

  for (const auto& tilePtr : d_game.getSession().getTiles())
  {
    for (const auto& arr : { tilePtr->getStructures(), tilePtr->getArmies() })
    {
      if (const auto* matchObj = checkArray(arr))
        return matchObj;
    }
  }

  return nullptr;
}
