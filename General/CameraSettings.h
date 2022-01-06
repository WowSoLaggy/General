#pragma once

#include <LaggySdk/Math.h>
#include <LaggySdk/Vector.h>


class CameraSettings
{
public:
  static constexpr Sdk::Vector3F Up = { 0.0f, 0.0f, 1.0f };
  static constexpr float Distance = 10.0f;
  static constexpr float Yaw = Sdk::degToRad(-90.0f);
  static constexpr float Pitch = Sdk::degToRad(45.0f);
};
