#pragma once

#include <LaggyDx/ICamera.h>


class CameraController
{
public:
  static std::unique_ptr<Dx::ICamera> createDefaultCamera();
};
