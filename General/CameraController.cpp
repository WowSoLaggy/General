#include "stdafx.h"
#include "CameraController.h"

#include "CameraSettings.h"

#include <LaggyDx/Game.h>


std::unique_ptr<Dx::ICamera> CameraController::createDefaultCamera()
{
  auto camera = Dx::ICamera::createCamera(Dx::Game::get().getRenderDevice().getResolution());
  CONTRACT_ASSERT(camera);

  camera->setUp(CameraSettings::Up);
  camera->setDistance(CameraSettings::Distance);
  camera->setYaw(CameraSettings::Yaw);
  camera->setPitch(CameraSettings::Pitch);

  camera->setLookAt({ 0.0f, 0.0f, 0.0f });

  return camera;
}
