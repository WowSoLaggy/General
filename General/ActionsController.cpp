#include "stdafx.h"
#include "ActionsController.h"

#include "CameraController.h"
#include "Game.h"


void ActionsController::createActionsInGame(Game& i_game)
{
  Dx::ActionsMap map;

  map.setAction(
    Dx::KeyboardKey::W,
    Dx::Action(std::bind(&CameraController::moveUpStart, &i_game.getSessionView().getCameraController())),
    Dx::ActionType::OnPress);
  map.setAction(
    Dx::KeyboardKey::W,
    Dx::Action(std::bind(&CameraController::moveUpStop, &i_game.getSessionView().getCameraController())),
    Dx::ActionType::OnRelease);

  map.setAction(
    Dx::KeyboardKey::S,
    Dx::Action(std::bind(&CameraController::moveDownStart, &i_game.getSessionView().getCameraController())),
    Dx::ActionType::OnPress);
  map.setAction(
    Dx::KeyboardKey::S,
    Dx::Action(std::bind(&CameraController::moveDownStop, &i_game.getSessionView().getCameraController())),
    Dx::ActionType::OnRelease);

  map.setAction(
    Dx::KeyboardKey::A,
    Dx::Action(std::bind(&CameraController::moveLeftStart, &i_game.getSessionView().getCameraController())),
    Dx::ActionType::OnPress);
  map.setAction(
    Dx::KeyboardKey::A,
    Dx::Action(std::bind(&CameraController::moveLeftStop, &i_game.getSessionView().getCameraController())),
    Dx::ActionType::OnRelease);

  map.setAction(
    Dx::KeyboardKey::D,
    Dx::Action(std::bind(&CameraController::moveRightStart, &i_game.getSessionView().getCameraController())),
    Dx::ActionType::OnPress);
  map.setAction(
    Dx::KeyboardKey::D,
    Dx::Action(std::bind(&CameraController::moveRightStop, &i_game.getSessionView().getCameraController())),
    Dx::ActionType::OnRelease);

  i_game.setActionsMap(std::move(map));
}
