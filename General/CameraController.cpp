#include "stdafx.h"
#include "CameraController.h"

#include "CameraSettings.h"

#include <LaggyDx/Game.h>
#include <LaggySdk/Math.h>


CameraController::CameraController()
{
  createDefaultCamera();
}


Dx::ICamera& CameraController::getCamera()
{
  CONTRACT_ASSERT(d_camera);
  return *d_camera;
}

const Dx::ICamera& CameraController::getCamera() const
{
  CONTRACT_ASSERT(d_camera);
  return *d_camera;
}


void CameraController::moveRightStart() { d_moveRight = true; }
void CameraController::moveRightStop() { d_moveRight = false; }
void CameraController::moveLeftStart() { d_moveLeft = true; }
void CameraController::moveLeftStop() { d_moveLeft = false; }
void CameraController::moveUpStart() { d_moveUp = true; }
void CameraController::moveUpStop() { d_moveUp = false; }
void CameraController::moveDownStart() { d_moveDown = true; }
void CameraController::moveDownStop() { d_moveDown = false; }
void CameraController::rotateCwStart() { d_rotateCw = true; }
void CameraController::rotateCwStop() { d_rotateCw = false; }
void CameraController::rotateCcwStart() { d_rotateCcw = true; }
void CameraController::rotateCcwStop() { d_rotateCcw = false; }


void CameraController::resetCamera()
{
  d_camera->setUp(CameraSettings::Up);
  d_camera->setDistance(CameraSettings::Distance);
  d_camera->setYaw(CameraSettings::Yaw);
  d_camera->setPitch(CameraSettings::Pitch);
}


void CameraController::update(const double i_dt)
{
  auto moveCamera = [&](const Sdk::Vector3F& i_direction)
  {
    const auto movement = Sdk::normalize(i_direction) * (float)(CameraSettings::SpeedLinear * i_dt);
    const auto& lookAt = getCamera().getLookAt();
    const auto newLookAt = Sdk::Vector3F{ lookAt.x + movement.x, lookAt.y + movement.y, 0.0f };
    getCamera().setLookAt(newLookAt);
  };

  auto rotateCamera = [&](const double i_direction)
  {
    const auto rotation = Sdk::sign(i_direction) * CameraSettings::SpeedAngular * i_dt;
    getCamera().setYaw(getCamera().getYaw() + (float)rotation);
  };

  if (d_moveRight && !d_moveLeft)
    moveCamera(getCamera().getRight());
  else if (d_moveLeft && !d_moveRight)
    moveCamera(getCamera().getLeft());

  if (d_moveUp && !d_moveDown)
    moveCamera(getCamera().getForward());
  else if (d_moveDown && !d_moveUp)
    moveCamera(getCamera().getBackward());

  if (d_rotateCw && !d_rotateCcw)
    rotateCamera(-1);
  else if (d_rotateCcw && !d_rotateCw)
    rotateCamera(1);
}


void CameraController::createDefaultCamera()
{
  d_camera = Dx::ICamera::createCamera(Dx::Game::get().getRenderDevice().getResolution());
  CONTRACT_ASSERT(d_camera);

  resetCamera();
}
