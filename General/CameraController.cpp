#include "stdafx.h"
#include "CameraController.h"

#include "CameraSettings.h"

#include <LaggyDx/Game.h>


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


void CameraController::update(const double i_dt)
{
  auto moveCamera = [&](const Sdk::Vector3F& i_direction)
  {
    const auto movement = Sdk::normalize(i_direction) * CameraSettings::Speed;
    const auto& lookAt = getCamera().getLookAt();
    const auto newLookAt = Sdk::Vector3F{ lookAt.x + movement.x, lookAt.y + movement.y, 0.0f };
    getCamera().setLookAt(newLookAt);
  };

  if (d_moveRight && !d_moveLeft)
    moveCamera(getCamera().getRight());
  else if (d_moveLeft && !d_moveRight)
    moveCamera(getCamera().getLeft());

  if (d_moveUp && !d_moveDown)
    moveCamera(getCamera().getForward());
  else if (d_moveDown && !d_moveUp)
    moveCamera(getCamera().getBackward());
}


void CameraController::createDefaultCamera()
{
  d_camera = Dx::ICamera::createCamera(Dx::Game::get().getRenderDevice().getResolution());
  CONTRACT_ASSERT(d_camera);

  d_camera->setUp(CameraSettings::Up);
  d_camera->setDistance(CameraSettings::Distance);
  d_camera->setYaw(CameraSettings::Yaw);
  d_camera->setPitch(CameraSettings::Pitch);
}
